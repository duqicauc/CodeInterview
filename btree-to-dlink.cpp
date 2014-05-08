#include <iostream>
using namespace std;

struct BSTreeNode{
	int value;
	BSTreeNode *m_pleft;
	BSTreeNode *m_pright;
};

void addBSTreeNode(BSTreeNode *&pCurrent,int value);
void inOrderBSTree(BSTreeNode* pBSTree);
void convertToDoubleList(BSTreeNode* pCurrent);
 
BSTreeNode *pHead=NULL;//指向循环队列头结点
BSTreeNode *pIndex=NULL;//指向前一个结点

int main(int argc, char const *argv[])
{
	BSTreeNode *pRoot=NULL;
    addBSTreeNode(pRoot,10);
    addBSTreeNode(pRoot,6);
    addBSTreeNode(pRoot,14);
    addBSTreeNode(pRoot,4);
    addBSTreeNode(pRoot,8);
    addBSTreeNode(pRoot,12);
    addBSTreeNode(pRoot,16);
    inOrderBSTree(pRoot);
    cout<<endl;

	return 0;
}

void addBSTreeNode(BSTreeNode *&pCurrent, int value)
{
	if (pCurrent==NULL){
		BSTreeNode *pTree = new BSTreeNode();
		pTree->m_pleft=NULL;
		pTree->m_pright=NULL;
		pTree->value = value;
		pCurrent=pTree;
	}else if (pCurrent->value > value){
		addBSTreeNode(pCurrent->m_pleft,value);
	}else if (pCurrent->value < value)
	{
		addBSTreeNode(pCurrent->m_pright,value);
	}else{
		cout << "Node repeated!" <<endl;
	}
}

void inOrderBSTree(BSTreeNode* pBSTree)
{
	if (pBSTree == NULL){
		return;
	}

	// left
	if (pBSTree->m_pleft != NULL)
	{
		inOrderBSTree(pBSTree->m_pleft);
	}

	// root
	convertToDoubleList(pBSTree);

	// right
	if (pBSTree->m_pright != NULL)
	{
		inOrderBSTree(pBSTree->m_pright);
	}
}


void convertToDoubleList(BSTreeNode *pCurrent)
{
	pCurrent->m_pleft = pIndex;
	if (pIndex == NULL)
	{
		pHead = pCurrent;
	}else{
		pIndex->m_pright=pCurrent;
	}

	pIndex = pCurrent;

	cout<<pCurrent->value<<" ";
}
