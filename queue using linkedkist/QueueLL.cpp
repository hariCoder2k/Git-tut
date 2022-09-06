#include<iostream>
using namespace std;


struct Node
{
		int data;
		Node* next;
};

struct Queue
{
	Node* front;
	Node* rear;
};

typedef Queue qt;

void init(qt &s)
{
	s.front=s.rear = NULL;
}

int enqueue(qt &s,int item)
{
	Node *temp = new Node();
	temp->data = item;
	temp->next = NULL;
	if ((s.front == NULL) && (s.rear == NULL))
	{
		s.front=s.rear=temp;
	}
	else{
		s.rear->next = temp;
		s.rear = temp;
	}
	return 1;
}

int dequeue(qt &s)
{
	Node *temp = new Node();
	if((s.front == NULL)&& (s.rear == NULL))
	{
		return -1;
	}
	else if(s.front == s.rear)
	{
		temp = s.front;
		s.front =s.rear = NULL;
	}
	else{
		temp = s.front;
		s.front = s.front->next;
	}
	int deq = temp->data;
	delete temp;
	return deq;
}

int peek(qt &s){
	if(s.front != NULL)
		return s.front->data;
	else
		return -1;
}

void printQueue(qt &s)
{
	Node* temp = s.front;
	if(temp == NULL)
		cout<<"\nEmpty Queue\n";
	else{
		cout<<"\n|";
		while(temp != NULL)
		{
			cout<<temp->data<<"|";
			temp=temp->next;
		}
	}
}


int main()
{
	qt s;
	init(s);
	int ch = 100;
	int item,status = 0;
			
	while(ch != -1){
	cout<<"\n----------------------------------------------"<<endl;;
	cout<<"\tMENU\n";
	cout<<"\t1.Enqueue value"<<endl;
	cout<<"\t2.Dequeue value"<<endl;
	cout<<"\t3.Peek top"<<endl;
	cout<<"\t4.Display"<<endl;
	cout<<"\t5.Exit"<<endl;
	cout<<"\n----------------------------------------------"<<endl;
	cout<<"\nEnter your choice:";
	cin>>ch;
	switch(ch){
		case 1:
		{
			cout<<"\nEnter value to be enqueued into the queue :";
			cin>>item;
			status = enqueue(s,item);
			if(status)
			{
				cout<<"\nEnqueued successfully\n";
			}
			break;
		}
		case 2:
		{
			status = 0;
			status = dequeue(s);
			if(status != -1)
			{
				cout<<"\nDequeued queue front is "<<status<<endl;
				
			}
			else{
				cout<<"\nQueue underflow"<<endl;
			}
			break;
		}
		case 3:
		{
			status = 0;
			status = peek(s);
			if(status != -1)
			{
				cout<<"\nQueue front without dequeue is "<<status<<endl;
				
			}
			else{
				cout<<"\nQueue underflow"<<endl;
			}
			break;
			
		}
		case 4:
		{
			cout<<"\n";
			printQueue(s);
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