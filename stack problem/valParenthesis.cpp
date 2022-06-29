#include<iostream>
#include<cstring>
#include<typeinfo>
using namespace std;

struct Stack 
{
	int top;
	int capacity;
	char *stack;
};

typedef Stack st;

void init(st &s,char no)
{
	s.top = -1;
	s.capacity = no;
	s.stack = new char[no];
}

bool isFull(st &s)
{
	if(s.top == s.capacity -1)
		return true;
	else
		return false;
}

bool isEmpty(st &s)
{
	if(s.top == -1)
		return true;
	else
		return false;
}
char pop(st &s)
{
	if (s.top != -1)
		return s.stack[s.top--];
	else
		return 0;
}

char peek(st &s)
{
	if (s.top != -1)
		return s.stack[s.top];
	else
		return 0;
}

int push(st &s,int item)
{
	if(s.top < s.capacity -1){
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
			cout<<"\n  |"<<s.stack[i] <<"|"<<endl;
			
		}
		cout<<"   "<<"--"<<endl;
	}
	else{
		cout<<"stack empty"<<endl;
	}
}

int main()
{
	string s;
	st stachar;
	cout<<"Enter the string:";
	getline(cin, s);
	init(stachar,s.length());
	for(int i=0;i<s.length();i++)
	{
		if ((s[i] == '{')||(s[i] =='(')||(s[i] =='['))
		{
			push(stachar,s[i]);
		}
		else if ((isEmpty())&&(s[i] ==')' && peek(stachar) == '(')||(s[i] ==']' && peek(stachar) == '[')||(s[i] =='}' && peek(stachar) == '{'))
		{	pop(stachar);
			
		}
	}
	 if(isEmpty(stachar))
            cout<<"\nPalindrome";
        else
            cout<<"\nNot Palindrome";
	return 0;
}