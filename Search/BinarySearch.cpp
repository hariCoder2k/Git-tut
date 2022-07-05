#include<iostream>
using namespace std;

int BinarySearchRecursive(int array[] , int target ,int left,int right)
{
	if(left>right){
		return -1;
	}
	
	int mid  = left + ((right-left )/2);
	if(array[mid] == target){
		return mid;
	}
	else if(target < array[mid])
	{
		return BinarySearchRecursive(array,target,left,mid-1);
	}
	else{
		return BinarySearchRecursive(array,target,mid+1,right);
	}
	
}

int main()
{
	int *arr,length,target;
	cout<<"Enter size:";
	cin>>length;
	arr = new int[length];
	for(int i=0;i<length;i++){
		cout<<"Enter value:";
		cin>>arr[i];
	}
	cout<<"Enter target to be found:";
	cin>>target;
	cout<<BinarySearchRecursive(arr,target,0,length-1);
} 