#ifndef _HJ_BST_
#define _HJ_BST_

#include<iostream>
#include "YK_File.h"

using namespace std; 

typedef struct tree_node
{
	struct tree_node *left;
	struct tree_node *right;
	char *food;
	int calories;

}tree_node;


	class HJ_BST
	{
	public:
		tree_node *t;
		tree_node *p;
		HJ_BST();
		tree_node* insert_tree(tree_node *tree,char *f,int cal);
		tree_node* searchBST(tree_node *root, char *f);
		void delete_tree(tree_node* root, char *f);
		void display_tree(tree_node* root);

	};
#endif