/*编写程序，按升序对栈进行排序（即最大元素位于栈顶）。最多只能使用一个额外的栈
存放临时数据，但不得将元素复制到别的数据结构中（如数组）。该栈支持如下操作：
push、pop、top和empty*/

#include <iostream>
#include <stack>

using namespace std;

template <typename T>
class StackWithSort
{
public:
	StackWithSort(){number = 0;}
	~StackWithSort(){}

	void push(int value);
	void pop();
	T top();
	bool empty();
	stack<T> sort();

private:
	stack<T> data;
	int number;
};

template <typename T>
void StackWithSort<T>::push(int value)
{
	data.push(value);
	number++;
}

template <typename T>
void StackWithSort<T>::pop()
{
	data.pop();
	number--;
}

template <typename T>
T StackWithSort<T>::top()
{
	return data.top();
}

template <typename T>
bool StackWithSort<T>::empty()
{
	return number == 0;
}

template <typename T>
stack<T> StackWithSort<T>::sort()
{
	stack<T> s1 = data;
	stack<T> reverseStack;
	int temp = 0;

	while(!s1.empty())
	{
		temp = s1.top();
		s1.pop();
		while(!reverseStack.empty())
		{
			if (temp >= reverseStack.top())
			{
				break;
			}
			// move the elements of reverse stack to the data 
			// until the temp is the biggest in the reverse stack
			s1.push(reverseStack.top());
			reverseStack.pop(); 
		}
		reverseStack.push(temp);
	}

	return reverseStack;
}

int main(int argc, char const *argv[])
{
	StackWithSort<int> ss;
	ss.push(7);
	ss.push(5);
	ss.push(2);
	ss.push(9);
	ss.push(12);

	cout << "before sorted:" <<endl; 
	while(!ss.empty())
	{
		cout << ss.top() <<endl;
		ss.pop();
	}

	ss.push(7);
	ss.push(5);
	ss.push(2);
	ss.push(9);
	ss.push(12);
	stack<int> r = ss.sort();

	cout << "after sorted:" <<endl; 
	while(!r.empty())
	{
		cout << r.top() <<endl;
		r.pop();
	}
	return 0;
}
