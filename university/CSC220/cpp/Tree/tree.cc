/*********************************************
Jared Dembrun
11/1/13

An executable which will take stdin and convert it into a tree, 
then traversing that tree in every way possible and displaying
the data in stdout
*********************************************/
#include <iostream>
#include <cstring>
#include "BinaryTree.cc"

using namespace std;

void clear(char[MAX_SIZE]);

int main()
{
	char line[MAX_SIZE];
	BinaryTree *btree = new BinaryTree();
	clear(line);

	while(cin.getline(line, MAX_SIZE))
	{
		int i = 0;
		while(line[i] != ' ')
		{
			btree->Add(line[i]);
			i++;
		}

		//print all things
		cout << "      Preorder: ";
		btree->PreOrder(btree->GetRoot()); 
		cout << endl;

		cout << "       Inorder: ";
		btree->InOrder(btree->GetRoot());
		cout << endl;

		cout << "     Postorder: ";
		btree->PostOrder(btree->GetRoot());
		cout << endl;

		cout << "ReverseInorder: ";
		btree->ReverseInorder(btree->GetRoot());
		cout << endl;

		btree->PrintTree(btree->GetRoot());

		//clear everything
		delete btree;
		btree = new BinaryTree();
		clear(line);
	}

	return 0;
}

void clear(char input[MAX_SIZE])//sets all indexes in the char array to ' '
{
	for(int i = 0; i < MAX_SIZE; i++)
		input[i] = ' ';
}
