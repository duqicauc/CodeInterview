/*
 * 使用两个队列实现一个栈
 * */

#include <iostream>
#include <queue>
#include <exception>

using namespace std;

template <typename T>
class Stack {
    queue<T> q1;
    queue<T> q2;
    bool q1_used, q2_used;
public:
    Stack();
    void push(T elem);
    void pop();
    T top() const;
    bool empty() const;
    int size() const;
};

template <typename T>
Stack<T>::Stack() {
    q1_used = true;
    q2_used = false;
}

template <typename T>
void Stack<T>::push(T elem) {
    if(q1_used == true) 
    {
        q1.push(elem);
    }
    if(q2_used == true) 
    {
        q2.push(elem);
    }
}

template <typename T>
void Stack<T>::pop()
{
    if (q1.empty() && q2.empty())
    {
        cout << "stack is empty " <<endl;
        throw exception();
    }

    if (q1_used == true)
    {
        while(q1.size() != 1)
        {
            q2.push(q1.front());
            q1.pop();
        }
        q1.pop();
        q1_used = false;
        q2_used = true;
        return;
    }

    if (q2_used == true)
    {
        while(q2.size() != 1)
        {
            q1.push(q2.front());
            q2.pop();
        }
        q2.pop();
        q2_used = false;
        q1_used = true;
        return;
    }

}

template<typename T>
T Stack<T>::top() const{
    if (q1.empty() && q2.empty())
    {
        cout << "stack is empty" <<endl;
        throw exception();
    }
    if(q1_used == true)
        return q1.back();
    if(q2_used == true)
        return q2.back();
    return 0;
}

template<typename T>
bool Stack<T>::empty() const{
    return q1.empty() && q1_used == true || q2.empty() && q2_used == true;
}

template <typename T>
int Stack<T>::size() const {
    if(!q1.empty() && q1_used == true) 
    {
        return q1.size();
    }
    if(!q2.empty() && q2_used == true) 
    {
        return q2.size();
    }
    return 0;
}

int main()
{
    /* 1、往空的栈里头加元素 */
    Stack<int> s1;
    s1.push(4);
    /* 往非空的栈里添加元素 */
    s1.push(5);
    s1.push(7);
    cout << s1.size() <<endl;
    cout << s1.top() <<endl;
    /* 从非空的栈里删除元素 */
    s1.pop();
    cout << s1.top() << endl;
    s1.pop();
    cout << s1.top() <<endl;
    s1.pop();
    /* 查看空的栈的栈顶元素，报错 */
    cout << s1.top() <<endl;
    /* 从空的栈里删除元素，报错*/
    s1.pop();
}
