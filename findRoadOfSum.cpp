#include <iostream>
#include <vector>

using namespace std;

struct BTreeNode
{
	int value;
	BTreeNode *left;
	BTreeNode *right;
};

BTreeNode *createBTree();
void preorder(BTreeNode* t);
void findRoadofSum(BTreeNode *pNode, int sum,std::vector<int>& path, int currenSum);

int main(int argc, char const *argv[])
{
	BTreeNode *root = createBTree();
	preorder(root);

	int expect = 22;
	std::vector<int> path;
	findRoadofSum(root,expect,path,0);
	return 0;
}

// create Binary Tree
BTreeNode *createBTree()
{
	BTreeNode *root;
	int ch;
	cin >> ch;
	if (ch == 0)
	{
		root = NULL;
	}
	else
	{
		root = new BTreeNode();
		root->value = ch;
		root->left = createBTree();
		root->right = createBTree();
	}
	return root;
}

void preorder(BTreeNode *t) 
{ 
     if(t!=NULL) 
     { 
       cout<<t->value; 
       preorder(t->left); 
       preorder(t->right); 
     } 
} 

void findRoadofSum(BTreeNode *pNode, int expectedSum, std::vector<int>& path, int currenSum)
{
	if (pNode == NULL){
		return;
	}

	// deal with root node
	currenSum += pNode->value;
	path.push_back(pNode->value);

	bool isLeaf = (pNode->left==NULL && pNode->right==NULL);
	if (currenSum == expectedSum && isLeaf){
		/* print current road*/
		std::vector<int>::iterator iter = path.begin();
        for(; iter != path.end(); ++ iter)
            std::cout << *iter << '\t';
        std::cout << std::endl;
	}

	// deal with the left child tree
	if (pNode->left != NULL)
	{
		findRoadofSum(pNode->left,expectedSum,path,currenSum);
	}

	// deal with the right child tree
	if (pNode->right != NULL)
	{
		findRoadofSum(pNode->right,expectedSum,path,currenSum);
	}

	// go back to the root node of parent
	currenSum -= pNode->value;
	path.pop_back();
}