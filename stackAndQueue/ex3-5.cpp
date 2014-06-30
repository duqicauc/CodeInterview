/*题目：
实现一个MyQueue类，该类用两个栈来实现一个队列*/

#include <iostream>
#include <stack>
#include <stdexcept>

using namespace std;

template <typename T>
class MyQueue
{
public:
	MyQueue();
	~MyQueue(){};

	void enqueue(T value);
	void dequeue();
	T gethead();
	int size();
	bool empty();

private:
	stack<T> stackNew;
	stack<T> stackOld;
	int number;

	/*tool function*/
	void shift();
};

template <typename T>
MyQueue<T>::MyQueue()
{
	number = 0;
}

template <typename T>
void MyQueue<T>::enqueue(T value)
{
	stackNew.push(value);
	number++;
}

template <typename T>
void MyQueue<T>::dequeue()
{
	shift();
	stackOld.pop();
	number--;
}

template <typename T>
T MyQueue<T>::gethead()
{
	shift();
	return stackOld.top();
}


//this function is very important
//only when the old stack is empty, we need to move the elements of 
//new stack to the old stack, this could reduce the moves between 
//the two stacks largely
template <typename T>
void MyQueue<T>::shift()
{
	if (stackOld.empty())
	{
		while(!stackNew.empty())
		{
			stackOld.push(stackNew.top());
			stackNew.pop();
		}
	}
}

template <typename T>
bool MyQueue<T>::empty()
{
	return number == 0;
}


int main(int argc, char const *argv[])
{
	// Declares queues with default deque base container
   	MyQueue<int> q1, q2;

   	q1.enqueue(1);

   	if ( q1.empty( ) )
    	cout << "The queue q1 is empty." << endl;
   	else
    	cout << "The queue q1 is not empty." << endl;

   	if ( q2.empty( ) )
    	cout << "The queue q2 is empty." << endl;
   	else
    	cout << "The queue q2 is not empty." << endl;

    q1.enqueue(4);
    q1.enqueue(5);

    while(!q1.empty())
    {
    	cout << q1.gethead() << endl;
    	q1.dequeue();
    }

	return 0;
}
