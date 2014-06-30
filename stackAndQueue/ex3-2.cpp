/*用一个数组实现3个栈*/

//方法2：采用动态分割，就是说有一个整个的存储空间供三个栈使用
//这时候，判断一个栈满的条件就是：整个存储空间都没有可存放空间

#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

const int default_capacity = 4;
const int numOfStack = 3;
const int total_size = default_capacity * numOfStack;

class StackData
{
public:
	StackData(int s,int c);
	~StackData();

	bool isInStack(int index);

	int start;
	int pointer;
	int size;
	int capacity;
};

StackData::StackData(int s, int c)
{
	start = s;
	pointer = start - 1;
	size = 0;
	capacity = c;
}

bool StackData::isInStack(int index)
{
	if (start <= index && index < start + capacity)
	{
		return true;
	}
	else if (start + capacity > total_size && index < (start+capacity)%total_size)
	{
		return true;
	}
	return false;
}

StackData::~StackData()
{

}

class UnFixedStack
{
public:
	UnFixedStack();
	~UnFixedStack();

	void push(int stack_num, int value);
	int pop(int stack_num);
	int top(int stack_num);
	bool isEmpty(int stack_num);
	int totalElements();

private:
	/* the tool function is regularly private*/
	int preElement(int index);
	int nextElement(int index);
	void shift(int stack_num);
	void expand(int stack_num);

	/* data */
	vector<StackData> stacks;
	int buffer[total_size];
};

UnFixedStack::UnFixedStack()
{
	// here we does not use heap memory because the type of 
	//"new Stack(0,default_capacity)" is the StackData*
	StackData stack(0,default_capacity);
	stacks.push_back(stack);
	StackData stack1(default_capacity,default_capacity);
	stacks.push_back(stack1);
	StackData stack2(default_capacity*2,default_capacity);
	stacks.push_back(stack2);
}

UnFixedStack::~UnFixedStack()
{

}

int UnFixedStack::totalElements()
{
	return stacks[0].size + stacks[1].size + stacks[2].size;
}

int UnFixedStack::preElement(int index)
{
	if (index == 0)
	{
		return total_size - 1;
	}
	else
	{
		return index - 1;
	}
}

int UnFixedStack::nextElement(int index)
{
	if (index + 1 == total_size)
	{
		return 0;
	}
	else
	{
		return index + 1;
	}
}

void UnFixedStack::shift(int stack_num)
{
	StackData *stack = &stacks[stack_num];
	if (stack->size >= stack->capacity)
	{
		int nextStack = (stack_num + 1) % numOfStack;
		shift(nextStack); //get into the next recur function
		stack->capacity++; //update the current stack's capacity
	}

	// act the shift
	for (int i = (stack->start + stack->capacity-1)%total_size; stack->isInStack(i); i = preElement(i))
	{
		buffer[i] = buffer[preElement(i)];
	}

	buffer[stack->start] = 0;
	stack->start = nextElement(stack->start);
	stack->pointer = nextElement(stack->pointer);
	stack->capacity--; //recovery or reduce the current stack's capacity
}

void UnFixedStack::expand(int stack_num)
{
	shift((stack_num+1)%numOfStack);
	stacks[stack_num].capacity++; // update the current stack's capacity
}

void UnFixedStack::push(int stack_num, int value)
{
	//notice!! here we use the pointer to update the element of stacks
	//don't use "StackData stack" like Java because it is a new memory
	//alloc in C++ while it is a reference in Java.
	StackData *stack = &stacks[stack_num];
	/*notice the condition which we think the stack is the full*/
	if (stack->size >= stack->capacity)
	{
		if (totalElements() >= total_size)
		{
			throw runtime_error("Out of space");
		}
		else
		{
			expand(stack_num);
		}
	}

	/*add the new element and update the stack's data*/
	stack->size++;
	stack->pointer = nextElement(stack->pointer);
	buffer[stack->pointer] = value;
}

int UnFixedStack::pop(int stack_num)
{
	StackData *stack = &stacks[stack_num];
	/* test the stack is empty or not*/
	if (stack->size == 0)
	{
		throw runtime_error("trying to pop an empty stack");
	}

	// pop the stack
	int value = buffer[stack->pointer];
	buffer[stack->pointer]=0;
	stack->size--;
	stack->pointer = preElement(stack->pointer);
	return value;
}

int UnFixedStack::top(int stack_num)
{
	StackData *stack = &stacks[stack_num];
	if (stack->size == 0)
	{
		throw runtime_error("trying to top an empty stack");
	}

	return buffer[stack->pointer];
}

bool UnFixedStack::isEmpty(int stack_num)
{
	StackData *stack = &stacks[stack_num];
	return stack->size == 0;
}

int main(int argc, char const *argv[])
{
	UnFixedStack unfixedStacks;

	//unfixedStacks.pop(0);
	unfixedStacks.push(0,10);
	unfixedStacks.push(0,11);
	unfixedStacks.push(0,2); 
	unfixedStacks.push(0,3);
	unfixedStacks.push(0,5); 

	cout << unfixedStacks.pop(0) << endl;
	cout << unfixedStacks.totalElements() << endl;

	if (unfixedStacks.isEmpty(1))
	{
		cout << "*********" <<endl;
	}
	unfixedStacks.push(1,111);
	unfixedStacks.push(1,112);
	unfixedStacks.push(1,113);
	unfixedStacks.push(1,114);

	cout << unfixedStacks.top(1) << endl;
	cout << unfixedStacks.totalElements() << endl;
	
	unfixedStacks.push(2,777);
	unfixedStacks.push(2,888);
	unfixedStacks.push(2,999);
	unfixedStacks.push(2,789);

	cout << unfixedStacks.totalElements() << endl;

	//unfixedStacks.push(2,6);
	return 0;
}
