/**
设计包含min函数的栈
定义栈的数据结构，要求添加一个min函数，能够得到栈的最小元素。
要求函数min/push/pop的时间复杂度都是O(1).
*/
#include <iostream>
#include <stack>
#include <assert.h>

using namespace std;

template <typename T> 
class StackWithMin
{
public:
    void push(T elem);
    void pop();
    T top() const;
    T min() const;
    int size() const;
    bool empty() const;
private:
    stack<T>  dataStack;
	stack<T>  minStack;
};

template <typename T>
void StackWithMin<T>::push(T elem)
{
	dataStack.push(elem);
	if (minStack.size() == 0 || minStack.top() > elem){
		minStack.push(elem);
	}else{
		minStack.push(minStack.top());
	}
}

template <typename T>
void StackWithMin<T>::pop()
{
	assert(dataStack.size()>0 && minStack.size()>0);

	minStack.pop();
	dataStack.pop();
}


template <typename T>
T StackWithMin<T>::top() const
{
	assert(dataStack.size()>0 && minStack.size()>0);

	return dataStack.top();
}


template <typename T> 
T StackWithMin<T>::min() const
{
	assert(dataStack.size()>0 && minStack.size()>0);
	
	return minStack.top();
}

template <typename T>
int StackWithMin<T>::size() const
{
	return dataStack.size();
}

template <typename T>
bool StackWithMin<T>::empty() const
{
	return dataStack.empty();
}

int main(int argc, char const *argv[])
{
	StackWithMin<int> ss;
	ss.push(4);
	ss.push(9);
	ss.push(1);
	ss.push(11);
	ss.push(6);
	cout << "min:" << ss.min() << endl;
	cout << "top:" << ss.top() << endl;
	ss.pop(); 
	cout << "min:" << ss.min() << endl;
	cout << "top:" << ss.top() << endl;
	if (ss.empty() == true)
	{
		cout << "the stack is empty!" <<endl;
	}
	else
	{
		cout << "the stack is not empty!" <<endl;
		cout << "the stack's size is:" << ss.size() <<endl;
	}
	return 0;
}

