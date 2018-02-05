#include "HJ_BST.h"
#include <string>

HJ_BST::HJ_BST()
{
	p = NULL;
}

tree_node* HJ_BST::insert_tree(tree_node *tree, char *f,int cal)
{
	int i=0;
	tree_node *newNode;
	if(tree == NULL){
		newNode=(tree_node*)malloc(sizeof(tree_node));
		newNode->food = f;
		newNode->calories = cal;
		newNode->left = NULL;
		newNode->right = NULL;
		p = newNode;
		return newNode;
	}
	else
	{
	
		if (stricmp(f, tree->food)<0)
		{
			tree->left = HJ_BST::insert_tree(tree->left,f,cal);
		
		}
		else if (stricmp(f, tree->food)>0)
		{
			tree->right = HJ_BST::insert_tree(tree->right,f,cal);
	
		}
		else if(stricmp(f, tree->food) == 0)
		{
			cout<<"\nAlready same food!\n"<<endl;
		}
	
	}

	p = tree;
	return p;
}

tree_node *HJ_BST::searchBST(tree_node *root, char *f)
{
	tree_node *node=NULL;
	node=root;
	if((root =='\0'))
	{
		cout<<"\nCan not found!."<<endl;
		return 0;
	}

	 if (stricmp(f, node->food)<0)
	  {
		 node=node->left;
		 searchBST(node,f);
	  }  
	  else if(stricmp(f, node->food)>0)
	  {
		node=node->right ;
		searchBST(node,f);
	  }
	  else if(stricmp(f, node->food) == 0)
	  {
		return root;
	  }


	}

void HJ_BST::delete_tree(tree_node* root, char *f)
{
   
	tree_node *parent,*succ, *succ_parent;
	tree_node *child;

	
	succ=NULL;
	succ_parent=NULL;
	tree_node *d=NULL;
	d=root;

	while((d !=NULL) && (stricmp(f, d->food)!=0))
	{
		parent = d;
		if(stricmp(f, d->food)<0)
		{
			d=d->left;
		}
		else if(stricmp(f, d->food)>0)
		{
			d=d->right ;
		}
	}
	if(d==NULL)
	{
		cout<<"Can not found food"<<endl;
		return;
	}

	if((d->left == NULL) && (d->right == NULL))
	{
		if(parent != NULL)
		{
			if(stricmp(d->food, parent->left->food)==0)
			{
				parent->left=NULL;
			}
			else 
			{
				parent->right=NULL;
			}
		}
		else root=NULL;
	}

	else if((d->left == NULL) || (d->right == NULL))
	{
		child=NULL;
		if(d->left != NULL)
			child=d->left;
		else 
			child=d->right;

		if(parent != NULL){
			if(parent->left == d) 
				parent->left=child;
			else
				parent->right=child;
		}
		else root=child;
	}

	else 
	{
		succ_parent=d;
		succ=d->left;
		while(succ->right != NULL)
		{
			succ_parent=succ;
			succ=succ->right;
			succ->right=succ->right;
		}
		if(succ_parent->left==succ)
			succ_parent->left=succ->left;
		else 
			succ_parent->right=succ->left;
		d->food=succ->food;
		d=succ;

	}
	free(d);
	
} 


	

void HJ_BST::display_tree(tree_node* root)
{
	if(root!=NULL){
		display_tree(root->left);
		cout<<"food : "<<root->food<<"\t\tcal : "<<root->calories<<endl;
		display_tree(root->right);
	}
}