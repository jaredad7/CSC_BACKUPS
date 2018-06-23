#ifndef HEAP_H
#define HEAP_H

template<class h_type>
class Heap
{
private:
	int size;
	struct tree_node
	{
		tree_node *parent;
		tree_node *right;
		tree_node *left;
		h_type data;
	}
	//the root is its own parent
	tree_node* root;

	//swap the values of two tree nodes
	void swap(tree_node* a, tree_node* b)
	{
		h_type temp = a->data;
		a->data = b->data;
		b->data = temp;
	}

	//sifts the root value down through the tree to garuantee a max heap
	void sift(tree_node *n)
	{
		if((n->left != NULL) && (n->right != NULL) && ((n->left->data > n->data) || (n->right->data > n->data)))
		{
			if(n->left->data > n->right->data)
			{
				swap(n->left, n);
				sift(n->left);
			}
			else
			{
				swap(n->right, n);
				sift(n->right);
			}
		}
	}

public:
	Heap()
	{
		root = NULL;
	}
	
	//call the function get_root() as the first parameter
	void add(h_type data)
	{

		if(!size)
		{
			root = new tree_node;
			root->parent = root;
			root->left = NULL;
			root->right = NULL;
			root->data = data;			
		}
		else
		{
			//find the level of the rightmost node
			tree_node *n = root;
			int right_level;
			for(right_level = 0; n->right != NULL; n = n->right);
			tree_node right_most = n;
			
			//find the level of the leftmost node
			n = root;
			int left_level;
			for(left_level = 0; n->left != NULL; n = n->left);
			tree_node left_most = n;

			//if a new level is required
			if(right_level == left_level)
			{
				left_most->left = new tree_node;
				n = left_most->left;
				n->left = NULL;
				n->right = NULL;
				n->parent = left_most;
				n->data = data;
			}
			else
			{
				tree_node *next_parent = node_finder(left_most);
				if(next_parent->left = NULL)
				{
					next_parent->left = new tree_node;
					n = next_parent->left;
				}
				else
				{
					next_parent->right = new tree_node;
					n = next_parent->right;
				}
				
				n->right = NULL;
				n->left = NULL;
				n->parent = next_parent;
				n->data = data;
			}
		}

		size++;		
	}
}
