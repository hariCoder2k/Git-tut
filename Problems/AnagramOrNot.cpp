// complexity nlogn
#include<iostream>
#include<algorithm>
using namespace std;

bool isAnagram(string str1,string str2)
{
	if(str1.length() != str2.length())
	{
		return false;
	}
	else{
		sort(str1.begin(),str1.end());
		sort(str2.begin(),str2.end());
		
		for(int i=0;i<str1.length();i++){
			if(str1[i] != str2[i])
				return false;	
		}
		return true;
	}
}

int main()
{
	string string1,string2;
	cin>>string1>>string2;
	if(isAnagram(string1,string2))
		cout<<string1<<" and "<<string2<<" are anagram";
	else
		cout<<string1<<" and "<<string2<<" are not anagram";
	return 0;
}
