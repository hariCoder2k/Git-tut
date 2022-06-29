#include<iostream>
#include<stack>
using namespace std;

bool valid(string s)
{
	stack<char> st;
        if(s.length() <=1) 
	{return false;}
	for(int i=0;i<s.length();i++)
	{
		if ((s[i] == '{')||(s[i] =='(')||(s[i] =='['))
		{
			st.push(s[i]);
		}
		else if ((!st.empty())&&((s[i] ==')') && (st.top() == '(')||(s[i] ==']' && st.top() == '[')||(s[i] =='}' && st.top() == '{')))
		{	
			st.pop();			
		}
		else if ((s[i] == '}')||(s[i] ==')')||(s[i] ==']')))
			return false;
	}
	if (st.empty())
	{
		return true;
	}
	else{
		return false;
	}
}


int main()
{
	string s;
	cout<<"Enter your string:";
	cin>>s;
	if(valid(s))
	{
		cout<<s<<" is a palindrome punctuation";
	}
	else
		cout<<s<<" is not a palindrome punctuation";
	return 0;
}


