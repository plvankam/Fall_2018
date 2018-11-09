#include<stdio.h>

struct node
{
	int data;
	struct node* left;
	struct node* right;
};

struct node* newNode(int data)
{
	// allocate memory for new node
	struct node* node = (struct node*)malloc(sizeof(struct node));
	// assign data to this node
	node->data = data;
	// initialize left and right children as null
	node->left  = NULL;
	node->right = NULL;
	return node;
};

int main()
{
	
	// create root
	struct node* root = newNode(1);
	//            1
	//          /   \
	//        NULL NULL
	root->left  = newNode(2);
	root->right = newNode(3);
	//            1
	//          /   \
	//         2     3  
	//      /   \   
	//    NULL NULL
	root->left->left = newNode(4);




	return 0;
}
