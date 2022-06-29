#include<iostream>
using namespace std;

#define MAX 5
struct Stack 
{
	int top;
	int stack[MAX];
};

typedef Stack st;

int pop(st &s)
{
	if (s.top != -1)
		return s.stack[s.top--];
	else
		return -1;
}

int peek(st &s)
{
	if (s.top != -1)
		return s.stack[s.top];
	else
		return -1;
}

int push(st &s,int item)
{
	if(s.top < MAX -1){
		s.top +=1;
		s.stack[s.top] = item;
		return 1;
	}
	else{
		return 0;
	}
}

void printStack(st &s)
{
	if(s.top != -1){
		for(int i = s.top ; i>-1; i--)
		{
			cout<<"  |"<<s.stack[i] <<"|"<<endl;
			
		}
		cout<<"   "<<"--"<<endl;
	}
	else{
		cout<<"stack empty"<<endl;
	}
}
int main()
{
	st s;
	s.top = -1;
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