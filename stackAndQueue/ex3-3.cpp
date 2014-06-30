/*题目：
设想有一堆盘子，堆太高可能会倒下来。因此，在现实生活中，盘子堆到一定高度时，我们就会另外堆一堆盘子。
请实现数据结构SetOfStacks，模拟这种行为。SetOfStacks应该由多个栈组成，并且在前一个栈填满时新建一个
栈。此外，SetOfStacks类的push()和pop()方法应该与只有一个栈的时候相同。*/

#include <iostream>
#include <stack>
#include <vector>
#include <stdexcept>

using namespace std;

const int capacity = 10;

class SetOfStacks
{
public:
	SetOfStacks();
	~SetOfStacks();

	void push(int value);
	void pop();
	int top();
	bool isEmpty();
	int size();

private:
	vector<stack<int>*> stacks;
	int numberOfStacks;
	int num;
};

SetOfStacks::SetOfStacks()
{
	stack<int> *s = new stack<int>();
	stacks.push_back(s);
	numberOfStacks = 1;
	num = 0;
}

SetOfStacks::~SetOfStacks()
{
	//here we need release the heap memory handly
	for (int i = 0; i < numberOfStacks; ++i)
	{
		delete stacks[i];
	}
}

void SetOfStacks::push(int value)
{
	if (stacks[numberOfStacks-1]->size() < 10)
	{
		stacks[numberOfStacks-1]->push(value);
	}
	else
	{
		stack<int> *s = new stack<int>();
		s->push(value);
		stacks.push_back(s);
		numberOfStacks++;
	}
	num++;
}

void SetOfStacks::pop()
{
	stacks[numberOfStacks-1]->pop();
	if (stacks[numberOfStacks-1]->size() == 1)
	{
		delete stacks[numberOfStacks-1];
	}
	num--;
}

int SetOfStacks::top()
{
	return stacks[numberOfStacks-1]->top();
}

bool SetOfStacks::isEmpty()
{
	return num == 0;
}

int SetOfStacks::size()
{
	return num;
}

int main(int argc, char const *argv[])
{	
	SetOfStacks s1;
   	s1.push( 10 );
   	s1.push( 20 );
   	s1.push( 30 );

 	int i = s1.size( );
   	cout << "The stack length is " << i << "." << endl;

    i = s1.top( );
    cout << "The element at the top of the stack is "
        << i << "." << endl;

    s1.pop( );

    i = s1.size( );
    cout << "After a pop, the stack length is " 
        << i << "." << endl;

    i = s1.top( );
    cout << "After a pop, the element at the top of the stack is "
        << i << "." << endl;
	return 0;
}