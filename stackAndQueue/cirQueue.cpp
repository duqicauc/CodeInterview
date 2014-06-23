/*自己实现一个循环队列，本质存储方式是数组存储*/

#include <iostream>
using namespace std;

const int SIZE = 100;

class CirQueue
{
public:
	bool isEmpty();
	bool isFull();
	void enQueue(int val);
	int deQueue();
	int getFront();

	CirQueue();
	~CirQueue();

private:
	int data[SIZE];
	int front;
	int rear;
	int count;
};

CirQueue::CirQueue()
{
	front = rear = -1;
	count = 0;
}

CirQueue::~CirQueue()
{

}

bool CirQueue::isEmpty()
{
	return count == 0;
}

bool CirQueue::isFull()
{
	return count == SIZE;
}

void CirQueue::enQueue(int val)
{
	if (count == SIZE)
	{
		cout << "Queue overflow" <<endl;
	}
	count++;
	rear = (rear+1)%SIZE;
	data[rear] = val;
} 

int CirQueue::deQueue()
{
	if (count == 0)
	{
		cout << "Queue underflow" <<endl;
	}
	front = (front+1)%SIZE;
	int temp = data[front];
	count--;
	return temp;
}

int CirQueue::getFront()
{
	if (count == 0)
	{
		cout << "Queue underflow" <<endl;
	}
	return data[(front+1)%SIZE];
}

int main(int argc, char const *argv[])
{
	CirQueue example;
	example.enQueue(2);
	example.enQueue(3);
	if (!example.isEmpty())
	{
		cout << example.getFront() <<endl;
	}
	return 0;
}
