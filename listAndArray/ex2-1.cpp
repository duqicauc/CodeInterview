/*编写代码，移除未排序列表中的重复节点*/

// 思考1：考虑用hash表记录已经出现过的节点
//，如果当前节点已经出现过，则删除，时间复杂度O(N),空间复杂度O(N)

// 思考2：使用两个指针p1和p2，p2负责查找和
//p1相同的节点，并删除，直到p1达到最后一个节点，时间复杂度O(n2),空间复杂度O(1)

#include <iostream>
#include <map>
using namespace std;

struct LNode
{
	int data;
	LNode *next;
};

class List
{
public:	
	List();
	void appendToTail(int data);
	void insertToHead(int data);
	void print();
	void deleteNode(int data);
	void clearNodes();
	void removeDupNode();
	void removeDupNodeWithHash();
	~List();
	/* data */
private:
	LNode *head;
	LNode *tail;
};

List::List()
{
	head = new LNode;
	head->next = NULL;
	tail = head;
}

void List::appendToTail(int data)
{
	LNode *p = new LNode;
	p->data = data;
	p->next = NULL;
	if (head == tail)
	{
		head->next = p;
	}
	else
	{
		tail->next = p;
	}
	tail = p; // update the location of tail
}

void List::insertToHead(int data)
{
	LNode *p = new LNode;
	p->data = data;
	p->next = NULL;

	if (head == tail)
	{
		tail = p; // update the location of the tail when the node is first node
	}
	p->next = head->next;
	head->next = p;
}

void List::print()
{
	if (head == tail)
	{
		cout << "the List is empty!" <<endl;
		return;
	}

	LNode *p = head->next;
	while(p != NULL)
	{
		cout << p->data << '\t';
		p = p->next;
	}
	cout << endl;
}

void List::deleteNode(int data)
{
	if (head == tail)
	{
		cout << "the list is empty!" << endl;
		return;
	}
	LNode *pre = head;
	while(pre->next != NULL)
	{
		if (pre->next->data == data)
		{
			pre->next = pre->next->next;
			if (pre->next == NULL) // if the node by deleted is the last one ,update the tail
			{
				tail = pre;
			}
		}
		pre = pre->next;
	}
}

void List::clearNodes()
{
	if (head == tail)
	{
		return;
	}
	LNode *pre = head;
	while(pre->next != NULL)
	{
		LNode *temp = pre->next;
		pre->next = pre->next->next;
		delete temp;
	}
	tail = head;
}

List::~List()
{

}

//2-1 
void List::removeDupNode()
{
	if (head == tail)
	{
		cout << "the linklist is empty!" <<endl;
		return;
	}

	LNode *p1 = head->next;
	LNode *p2;
	while(p1->next != NULL)
	{
		p2 = p1; // update the p2
		while(p2->next != NULL)
		{
			if (p1->data == p2->next->data)
			{
				LNode *temp = p2->next;
				p2->next = p2->next->next; // delete the p2->next node, so move p2 to the next
				delete temp;
				if (p2->next == NULL)
				{
					tail = p2;
				}
			}
			else
			{
				//the p2 will move to the next node
				p2 = p2->next;
			}
		}
		p1 = p1->next; // update the p1
	}
}

//2-1: use the hash table to hold the nowable node
void List::removeDupNodeWithHash()
{
	if (head == tail)
	{
		cout << "the linklist is empty!" <<endl;
		return;
	}

	map<int, bool> nodetable;
	LNode *p = head->next;
	LNode *pre = NULL;
	while(p != NULL)
	{
		if (nodetable[p->data])
		{
			LNode *temp = p;
			pre->next = p->next;
			delete temp;
		}
		else
		{
			nodetable[p->data] = true;
			pre = p;
		}
		p = p->next;
	}
}


int main(int argc, char const *argv[])
{
	List l1;
	l1.appendToTail(7);
	l1.appendToTail(5);
	l1.appendToTail(3);
	//l1.print();
	l1.insertToHead(7);
	l1.insertToHead(9);
	//l1.deleteNode(4);
	l1.insertToHead(7);
	l1.print();
	//l1.clearNodes();
	l1.removeDupNodeWithHash();
	l1.print();
	return 0;
}
