#include<iostream>
using namespace std;

struct Node
{
	int data;
	Node* next;
};

struct LinkedList
{
	Node* head;
};

void init(LinkedList &l)
{
	l.head = NULL;
}

int countList(LinkedList &l)
{
	int len=0;
	if(l.head == NULL)
	{
		return 0;
	}
	else{
		Node* temp = new Node();
		temp = l.head;
		while(temp && ++len ){
			temp = temp->next;
		}
		return len;
		
	}
}
void insertFirst(LinkedList &l,int value)
{
	Node* temp = new Node();
	temp->data = value;
	temp->next = l.head;
	l.head = temp;
	cout<<"\nInserted successfully\n";
}

void insertLast(LinkedList &l,int value)
{
	if(l.head == NULL)
	{
		insertFirst(l,value);
	}
	else{
			Node* temp = new Node();
			temp->data = value;
			temp->next = NULL;
			Node* iter = l.head;
			while(iter->next != NULL)
				iter = iter->next;
			iter->next = temp;
			cout<<"\nInserted successfully\n";			
	}
	
}

void insertMid(LinkedList &l,int value,int after)
{
	if(l.head == NULL)
	{
		insertFirst(l,value);
	}
	else{
			Node* temp = new Node();
			temp->data = value;
			Node* iter = l.head;
			while(iter->data != after){
				if(iter->next != NULL)
					iter = iter->next;
				else
				{
					cout<<"\nAfter element not found\n";
					return;
				}
			}
			temp->next = iter->next;
			iter->next = temp;
			cout<<"\nInserted successfully\n";			
	}
	
}

void deleteFirst(LinkedList &l)
{
	if (l.head == NULL)
		cout<<"\nEmpty List\n";
	else 
	{
		Node* temp = l.head;
		l.head = l.head->next;
		cout<<"\nThe value of node that is deleted is "<<temp->data;
		delete temp;
		
	}
}

void deleteLast(LinkedList &l)
{
	Node* temp;
	if (l.head == NULL)
		cout<<"\nEmpty List\n";
	else if(l.head->next == NULL)
	{
		cout<<endl;
		deleteFirst(l);
	}
	else{
		
		Node* iter = l.head;
		while(iter->next->next != NULL)
		{
			iter = iter->next;
		}
		temp = iter->next;
		iter->next = NULL;
		cout<<"\nThe value of deleted element is "<<temp->data;
		delete temp;		
	}
}
Node* search(LinkedList &l,int value)
{
	if(l.head == NULL)
	{
		cout<<"\nEmpty list";
	}
	else{
		Node* temp = l.head;
		while(temp!= NULL)
		{
			if(temp->data == value)
			{
				return temp;
			}
			else{
				temp = temp->next;
			}
		}
			return NULL;
	}
	
}
void deleteMiddle(LinkedList &l,int value)
{
	if(l.head == NULL)
		cout<<"\nEmpty List"<<endl;
	else{
		int found = 0;
		Node* curr, *prev;
		curr = prev =l.head;
		if(l.head->data == value)
		{
			deleteFirst(l);
		}
		while(curr != NULL)
		{
			
			if(curr->data != value)
			{
				prev = curr;
				curr = curr->next;
			}
			else{
				found = 1;
				break;
			}
				
		}
		if(found)
		{
			cout<<"\nElement to be deleted is "<<curr->data;
			Node* temp = curr;
			prev->next = curr->next;
			temp = NULL;
			
		}
		else
			cout<<"\nElement not found\n";
	}
	
}

void deleteRange(LinkedList &l,int from,int to)
{
	Node* temp;
	if (l.head == NULL)
		cout<<"\nEmpty List\n";
	else
	{
		Node* fromPrevNode, *toNode,*iter,*iter2;
		iter = l.head;
		iter2 = l.head;
		while(iter)
		{
			if(iter2->data != from){
				iter = iter2;
				iter2 = iter2->next;
			}
			else{
				fromPrevNode = iter;
				cout<<"iter->data"<<iter->data;
				toNode = search(l,to);
				cout<<"\nto->data"<<toNode->data;
				if(toNode)
				{
					fromPrevNode->next = toNode->next;
					cout<<"\nDeletion complete\n";
					return;
				}
				else{
					cout<<"\nElement not found\n";
					return;
				}
			}
		}
	}
	
}

void printLinkedList(LinkedList &l)
{
	if(l.head == NULL)
	{
		cout<<"\nEmpty list"<<endl;
	}
	else{
		Node* temp = l.head;
		cout<<endl;
		while(temp)
		{
			cout<<"->"<<temp->data;
			temp = temp->next;
		}
		cout<<endl;
	}
}

void rotate(LinkedList &l,int k)
{
	if(!l.head || !l.head->next || k==0){
		cout<<"\nRotation not possible\n";
		return;
	}
	Node* iter = l.head;
	int len = 1;
	while(iter->next && ++len)
		iter=iter->next;
	iter->next = l.head;
	k = k%len;
	k = len-k;
	while(k--)
		iter = iter->next;
	l.head = iter->next;
	iter->next= NULL;
	cout<<"\nRotation complete\n";
}

int main()
{
	LinkedList l;
	init(l);
	int ch = 100;
	int item,status = 0;		
	while(ch != -1){
	cout<<"\n----------------------------------------------"<<endl;;
	cout<<"\tMENU\n";
	cout<<"\t1.Insert at First\n";
	cout<<"\t2.Insert at Last\n";
	cout<<"\t3.Insert after element\n";
	cout<<"\t4.Delete First element\n";
	cout<<"\t5.Delete last element\n";
	cout<<"\t6.Delete element\n";
	cout<<"\t7.Delete Range\n";
	cout<<"\t8.Rotate right\n";
	cout<<"\t9.Search\n";
	cout<<"\t10.Print List:\n";
	cout<<"\t11.Length of the list\n";
	cout<<"\t12.Exit\n";
	cout<<"\n----------------------------------------------\n"<<endl;
	cout<<"Enter your choice:";
	cin>>ch;
	switch(ch)
	{
		case 1:
		{
			cout<<"\nEnter value to be inserted first:";
			cin>>item;
			insertFirst(l,item);
			break;
		}
		case 2:
		{
			cout<<"\nEnter value to be inserted last:";
			cin>>item;
			insertLast(l,item);
			break;			
		}
		
		case 3:
		{
			cout<<"\nEnter value to be inserted :";
			cin>>item;
			cout<<"\nEnter value to be the element should be inserted:";
			cin>>status;
			insertMid(l,item,status);
			break;
		}
		
		case 4:
		{
			deleteFirst(l);
			break;
		}
		case 5:
		{
			deleteLast(l);
			break;
		}
		case 6:
		{
			cout<<"Enter the element to be deleted:";
			cin>>item;
			deleteMiddle(l,item);
			break;
		}
		case 7:
		{
			cout<<"Enter the FROM element to be deleted:";
			cin>>item;
			cout<<"\nEnter the TO element to be deleted:";
			cin>>status;
			deleteRange(l,item,status);
			break;
		}
		case 8:
		{
			cout<<"Enter no. of rotations needed:";
			cin>>item;
			rotate(l,item);
			break;
		}
		case 9:
		{
			cout<<"\nEnter the element to be searched:";
			cin>>item;
			Node* temp = search(l,item);
			if(temp)
				cout<<"\nFound\n";
			else
				cout<<"\nElement does not exist\n";
			break;
		}
		case 10:
		{
			printLinkedList(l);
			break;
		}
		case 11:
		{
			item = countList(l);
			cout<<"\nLength of the list is "<<item<<endl;
			break;
		}
		case 12:
		{
			ch = -1;
			break;
		}
		default: break;
	}
	
	}
	return 0;
}