/*如何使用一个数组实现三个栈???
此处，应该跟面试官讨论，问清楚他对栈的具体要求，以及对实现算法的空间和时间效率等*/

#include <iostream>
using namespace std;

const int SIZE = 100;

//方法一：对数组的全部容量固定分割，弱点是空间利用效率不佳，如果提前能预估每个栈大概的容量
//并作出相应的分配权重，也算是一方面优化
class FixedStack
{
public:
	FixedStack(int stack_num);
	~FixedStack();

	bool isEmpty(int stack_num);
	bool isFull(int stack_num);
	void push(int stack_num,int val);
	int pop(int stack_num);
	int top(int stack_num);

private:
	int *buffer;
	int *stack_pointers; 
	int abposition(int stack_num); // key tool function
};

int FixedStack::abposition(int stack_num)
{
	return stack_num*SIZE + stack_pointers[stack_num];
}

FixedStack::FixedStack(int stack_num)
{
	buffer = new int[stack_num * SIZE];
	for (int i = 0; i < stack_num*SIZE; ++i)
	{
		buffer[i] = 0;
	}

	stack_pointers = new int[stack_num];
	for (int i = 0; i < stack_num; ++i)
	{
		stack_pointers[i] = -1;
	}
}

FixedStack::~FixedStack()
{
	delete[] buffer;
	delete[] stack_pointers;
}

bool FixedStack::isEmpty(int stack_num)
{
	return stack_pointers[stack_num] == -1;
}

bool FixedStack::isFull(int stack_num)
{
	return ((stack_pointers[stack_num]+1) == SIZE);
}

void FixedStack::push(int stack_num,int val)
{
	if (stack_pointers[stack_num]+1 >= SIZE)
	{
		cout << "the stack " << stack_num << " is full" <<endl;
		return;
	}

	stack_pointers[stack_num]++;
	buffer[abposition(stack_num)] = val;
}

int FixedStack::pop(int stack_num)
{
	if (stack_pointers[stack_num] == -1)
	{
		cout << "the stack " << stack_num << " is empty" <<endl;
		return -1;
	}

	int result = buffer[abposition(stack_num)];
	stack_pointers[stack_num]--;
	return result;
}

int FixedStack::top(int stack_num)
{
		if (stack_pointers[stack_num] == -1)
	{
		cout << "the stack " << stack_num << " is empty" <<endl;
		return -1;
	}

	return buffer[abposition(stack_num)];
}

void isEmpty_test()
{
	FixedStack s1(3);
	if (s1.isEmpty(0))
	{
		cout << "the stack is empty" <<endl;
	}
	s1.pop(0);
}

void full_push_test()
{
	FixedStack s2(3);
	for (int i = 0; i < 100; ++i)
	{
		s2.push(1,i);
	}

	if (s2.isFull(1))
	{
		cout << "******" <<endl;
	}
	s2.push(1,4);
	cout << s2.pop(1) <<endl;
	cout << s2.top(1) <<endl;
	s2.push(1,11);
	cout << s2.top(1) <<endl; 
}

int main(int argc, char const *argv[])
{
	//isEmpty_test();
	full_push_test();
	return 0;
}
