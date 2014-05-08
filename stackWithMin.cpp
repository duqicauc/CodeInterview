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
    T top();
    T min();
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
T StackWithMin<T>::top()
{
	assert(dataStack.size()>0 && minStack.size()>0);

	return dataStack.top();
}


template <typename T> 
T StackWithMin<T>::min()
{
	assert(dataStack.size()>0 && minStack.size()>0);
	
	return minStack.top();
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
	return 0;
}

