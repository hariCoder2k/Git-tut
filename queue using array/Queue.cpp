#include<iostream>
#include<cstring>
#include<typeinfo>
using namespace std;

struct Queue
{
	int front;
	int rear;
	int capacity;
	int *queue;
};

typedef Queue qt;

void init(qt &s,int no)
{
	s.front = s.rear = -1;
	s.capacity = no;
	s.queue = new int[no];
}

int enqueue(qt &s,int item)
{
	if(s.front == -1)
	{
		s.front = 0;
		s.rear = 0;
		s.queue[s.rear] = item;
		return 1;
	}
	else if(s.rear != s.capacity -1 )
	{
		s.rear+=1;
		s.queue[s.rear] = item;
		return 1;
	}
	else
		return 0;
}

int dequeue(qt &s)
{
	int dat=0;
	if((s.front == -1)&& (s.rear == -1))
	{
		return -1;
	}
	else if (s.front == s.rear)
	{
		dat = s.queue[s.front];
		s.front = s.rear = -1;
		s.queue[s.front] = 0;
	}
	else{
		dat = s.queue[s.front];
		s.queue[s.front] = 0;
		s.front +=1;
	}
	return dat;
}
int peek(qt &s){
	if(s.front != -1)
		return s.queue[s.front];
	else
		return -1;
}
void printQueue(qt &s)
{
	if ((s.front == -1)&&(s.rear == -1))
	{
		cout<<"\nQueue is empty\n";
	}
	else
	{
		cout<<"\n|";
		for (int i = s.front;i<=s.rear;i++)
		{
			cout<<s.queue[i]<<"|";
		}
	}
		
}

int main()
{
	qt s;
	int no;
	cout<<"Enter queue capacity:";
	cin>>no;
	init(s,no);
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
			else{
				cout<<"\nQueue overflow"<<endl;
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