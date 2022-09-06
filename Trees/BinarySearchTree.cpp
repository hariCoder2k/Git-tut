#include<iostream>
using namespace std;

struct Bst
{
	int data;
	Bst *left,*right;
	
};


typedef Bst Bst;
Bst* insert(Bst* p,int value)
{
	if(p == NULL)
	{
		p = new Bst();
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
		else
		{
			cout<<"\nData already exist"<<endl;
		}
	}

	return p;
}

void inorderTraversal(Bst *root)
{
	if(root != NULL){
	inorderTraversal(root->left);
	cout<<"->"<<root->data;
	inorderTraversal(root->right);
	}
}

void  preorderTraversal(Bst *p)
{
	if( p != NULL){
	cout<<"->"<<p->data;
	preorderTraversal(p->left);
	preorderTraversal(p->right);
	}
}

void  postorderTraversal(Bst *p)
{
	if( p != NULL){
	postorderTraversal(p->left);
	postorderTraversal(p->right);
	cout<<"->"<<p->data;
	}
}

int findMax(Bst* root)
{
	if(root)
	{
		while(root->right)
			root = root->right;
		return root->data;
	}
	else
		return -1;
}

int findMin(Bst* root)
{
	if(root)
	{
		while(root->left)
			root = root->left;
		return root->data;
	}
	else
		return -1;
}

Bst* deleteNode(Bst* root, int value)
{
	//link for reference https://www.geeksforgeeks.org/binary-search-tree-set-2-delete/
}


int main()
{
	Bst *b = NULL;
	int choice = 100,item,status = 0;	
	while(choice != -1)
	{
	cout<<"\n----------------------------------------------"<<endl;;
	cout<<"\tMENU\n";
	cout<<"\t1.Insert value"<<endl;
	cout<<"\t2. Inorder traversal"<<endl;
	cout<<"\t3. preorder traversal"<<endl;
	cout<<"\t4. postorder traversal"<<endl;
	cout<<"\t5. Find minimum"<<endl;
	cout<<"\t6.Find Manimum 2"<<endl;
	cout<<"\t7.Exit"<<endl;
	cout<<"\n----------------------------------------------"<<endl;
	cout<<"\nEnter your choice:";
	cin>>choice;
	switch(choice)
		{
			case 1:
			{	
				cout<<"Enter the value to be inserted:";
				cin>>item;
				if(b == NULL)
				{
					
					b = insert(b,item);
				}
				else
				{
					b = insert(b,item);
				}
				break;
			}
			case 2:
			{	
				cout<<endl;
				inorderTraversal(b);
				cout<<endl;
				break;
			}
			
			case 3:
			{
				cout<<endl;
				preorderTraversal(b);
				cout<<endl;
				break;
			}
			
			case 4:
			{
				cout<<endl;
				postorderTraversal(b);
				cout<<endl;
				break;
			}
			
			case 5:
			{
				int maxRight = findMax(b);
				if(maxRight != -1)
				cout<<endl<<maxRight<<endl;
				else
					cout<<"Tree is NULL";
				break;
			}
			
			case 6:
			{
				int minLeft = findMin(b);
				if(minLeft != -1)
					cout<<endl<<minLeft<<endl;
				else
					cout<<"Tree is NULL";
				break;
			}
			case 7:
			{
				choice = -1;
				break;
			}
			default:
			cout<<"\n invalid choiceoice\n";
		}
	}
}