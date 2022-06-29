#include<iostream>
using namespace std;


struct Node
{
		int data;
		Node* next;
};

struct Stack
{
	Node* top;
};

typedef Stack st; 

void init(st &s)
{
	s.top = NULL;
}

int pop(st &s)
{
	if (s.top != NULL){
		int dat = s.top->data;
		s.top = s.top->next;
		return dat;
	}
	else
		return -1;
}

int peek(st &s)
{
	if (s.top != NULL)
		return s.top->data;
	else
		return -1;
}

int push(st &s,int item)
{
		Node* temp = new Node();
		temp->data=item;
		temp->next = s.top;
		s.top = temp;
		return 1;
}

void printStack(st &s)
{
	Node* temp = s.top;
	if(temp == NULL)
		cout<<"\nStack is empty\n";
	else{
		while(temp != NULL)
		{
			cout<<"  |"<<temp->data <<"|"<<endl;
			temp=temp->next;
		}
		cout<<"   "<<"--"<<endl;
	}
}

int main()
{
	st s;
	init(s);
	int ch = 100;
	int item,status = 0;
			
	while(ch != -1){
	cout<<"\n----------------------------------------------"<<endl;;
	cout<<"\tMENU\n";
	cout<<"\t1.Push value"<<endl;
	cout<<"\t2.Pop value"<<endl;
	cout<<"\t3.Peek top"<<endl;
	cout<<"\t4.Display"<<endl;
	cout<<"\t5.Exit"<<endl;
	cout<<"\n----------------------------------------------"<<endl;
	cout<<"\nEnter your choice:";
	cin>>ch;
	switch(ch){
		case 1:
		{
			cout<<"\nEnter value to be pushed into the stack :";
			cin>>item;
			status = push(s,item);
			if(status)
			{
				cout<<"\nPushed successfully\n";
			}
			else{
				cout<<"\nStack overflow"<<endl;
			}
			break;
		}
		case 2:
		{
			status = 0;
			status = pop(s);
			if(status != -1)
			{
				cout<<"\nPopped stack top is "<<status<<endl;
				
			}
			else{
				cout<<"\nStack underflow"<<endl;
			}
			break;
		}
		case 3:
		{
			status = 0;
			status = peek(s);
			if(status != -1)
			{
				cout<<"\nStack top without pop is "<<status<<endl;
				
			}
			else{
				cout<<"\nStack underflow"<<endl;
			}
			break;
			
		}
		case 4:
		{
			cout<<"\n";
			printStack(s);
			break;
		}
		case 5:
		{
			ch = -1;
			break;
		}
		default:
		cout<<"\n Invalid case\n";
		break;
		
		}
	}
	return 0;
}