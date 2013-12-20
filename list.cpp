/*
 * 求链表中的倒数第k个结点
 * 基本思路:
 * (1)将pSlow和pFast同时指向链表的头部
 * (2)将快指针向后移动K位
 * (3)快慢指针同时移动，当pFast为空时，pSlow就指向倒数第K个节点
 * (4)结束
 * */

#include <iostream>
using namespace std;

typedef struct node* nodeptr;
typedef nodeptr list;
typedef struct node{
    int data;
    nodeptr next;
    node(int i){data = i;next = NULL;}
}listnode;

list createListNode(int value)  
{  
     nodeptr node = new listnode(0);  
     node->data = value;  
     node->next = NULL;  
     return node;  
} 

list createList(int n)
{  
    list l = new listnode(0);
    l->next = NULL;
    
    /* 构建具有n个结点的链表 */
    int i, temp;
    for (i = 0; i < n; i++)
    {
        cout << "输入第" << i << "个结点:";
        cin >> temp;
        nodeptr p = createListNode(temp);
        p->next = l->next;
        l->next = p;
    }
    return l;
}

nodeptr findKthFromEnd(list pHead, int k)
{
    if(pHead == NULL || pHead->next == NULL || k == 0)
        return NULL;

    nodeptr pAhead = pHead->next;
    nodeptr pBehind = NULL;

    /* 将快指针从第一个结点向后移动k-1步 */
    for (int i = 1; i < k; i++)
    {
        if(pAhead->next != NULL)
            pAhead = pAhead->next;
        else
            return NULL;
    }
    
    /* 从第k步开始，慢指针也开始移动，这样
     * 快慢指针之间相隔k-1步，那么，从快
     * 指针起算第一个结点，那么到慢指针指向
     * 的结点就恰好是第k个，之间相隔k-1个步*/
    pBehind = pHead->next;
    while(pAhead->next != NULL)
    {
        pAhead = pAhead->next;
        pBehind = pBehind->next;
    }

    return pBehind;
}

int main()
{
    list l = createList(6);
   
    nodeptr ptr = l->next;
    while(ptr != NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout <<endl;
    
    nodeptr p = findKthFromEnd(l, 3);
    if(p != NULL)
        cout << p->data <<endl;

    p = findKthFromEnd(l, 6);
    if(p != NULL)
        cout << p->data <<endl;
    return 0;
}
