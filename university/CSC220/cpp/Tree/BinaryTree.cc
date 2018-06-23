/**************************************
Jared Dembrun
11/1/13

A binary tree class of types char
This binary tree automatically orders any data it is given
***************************************/
#include <iostream>

using namespace std;

#define MAX_SIZE 100

class BinaryTree
{

private:
//******Private Memebers********************//
	struct treeNode
	{
		char data;
		treeNode *right, *left;//a left child and a right child, right is always greater
	};
	treeNode *root;//the top of the tree
	

public:
	BinaryTree()
	{
		root = NULL;
	}
	
	void Add(char data)//adds a character in its rightful place
	{
		if(root == NULL)
		{
			root = new treeNode;
			root->data = data;
			root->right = NULL;
			root->left = NULL;
		}
		else if((data > 33) && (data < 126))//ensure the character is legitimate
		{
			treeNode *iter = root;
			treeNode *temp;//track which treeNode is last before the NULL one
			bool end = false;//determine when we must create a new leaf
			do
			{
				if(iter == NULL)//if we are at the new leaf
				{
					iter = new treeNode;
					iter->data = data;
					iter->left = NULL;
					iter->right = NULL;
					end = true;
					if(data < temp->data)
						temp->left = iter;
					else if(data >= temp->data)
						temp->right = iter;					
				}
				else if(data < iter->data)//left if data is smaller
				{
					temp = iter;//before moving iter, set temp
					iter = iter->left;
				}

				else if(data >= iter->data)//otherwise, data must be larger
				{
					temp = iter;//before moving iter, set temp
					iter = iter->right;
				}
			}while(!end);
		}
	}

	treeNode* GetRoot()
	{
		return root;
	}
	
	void PrintTree(treeNode* n, int level = 0)//Traverses and prints the tree
	{
		if (n == NULL)
            		return;

      		PrintTree(n->right, level+1);
      		for (int i=0; i<level; i++)
            		cout << "   "; // 3 spaces
      		cout << n->data << endl;
      		PrintTree(n->left, level+1);
	}
	void InOrder(treeNode* n, int level = 0)// Prints the Values LVR
	{
      		if (n == NULL)
            		return;

      		InOrder(n->left, level+1);
      		cout << n->data;
      		InOrder(n->right, level+1);
	}

	void ReverseInorder(treeNode* n, int level = 0)//Prints the Values RVL
	{
      		if (n == NULL)
            		return;

      		ReverseInorder(n->right, level+1);
      		cout << n->data;
      		ReverseInorder(n->left, level+1);
	}

	void PreOrder(treeNode* n, int level = 0)//Prints the Values RVL
	{
      		if (n == NULL)
            		return;

      		cout << n->data;
		
      		PreOrder(n->left, level+1);
		PreOrder(n->right, level+1);
	}

	void PostOrder(treeNode* n, int level = 0)//Prints the Values RVL
	{
      		if (n == NULL)
            		return;

		PostOrder(n->left, level+1);
		PostOrder(n->right, level+1);
      		cout << n->data;
	}
};
