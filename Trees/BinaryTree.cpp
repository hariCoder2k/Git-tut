#include<iostream>
using namespace std;

struct TreeNode
{
	int data;
	TreeNode* left;
	TreeNode *right;
};

typedef TreeNode Node;

Node* init()
{
	cout<<"Enter root";
	int root;
	cin>>root;
	Node* newRoot = new Node();
	newRoot->data = root;
	newRoot->left= newRoot->right = NULL;
	return newRoot;
}
Node* insert(Node* p,int value)
{
	if(p == NULL)
	{
		p = new Node();
		p->data = value;
		p->left = p->right = NULL;
	}
	else{
		if(p->data > value)
		{
			p->left = insert(p->left,value);
		}
		else if(p->data < value)
		{
			p->right = insert(p->right,value);
		}
		else if(p->data == value)
		{
			cout<<"\nData already exist"<<endl;
		}
	}
	return p;
}

void  inorderTraversal(Node *p)
{
	
	if( p != NULL){
	inorderTraversal(p->left);
	cout<<p->data<<"|";
	inorderTraversal(p->right);
	}
}

void  preorderTraversal(Node *p)
{
	if( p != NULL){
	cout<<p->data<<"|";
	preorderTraversal(p->left);
	preorderTraversal(p->right);
	}
}

void  postorderTraversal(Node *p)
{
	if( p != NULL){
	postorderTraversal(p->left);
	postorderTraversal(p->right);
	cout<<p->data<<"|";
	}
}

int main()
{
	Node* root = NULL;
	int choice = 1,value;
	root = init();
	while (choice)
	{
		cout<<"Enter value:";
		cin>>value;
		insert(root,value);
		cout<<"ch?";
		cin>>choice;
	}
	cout<<"Inorder Traversal:"<<endl;
	inorderTraversal(root);
	cout<<"\nPreorder Traversal:"<<endl;
	preorderTraversal(root);
	cout<<"\nPostorder Traversal:"<<endl;
	postorderTraversal(root);
	
	
}