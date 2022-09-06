#include<iostream>
using namespace std;

void swap (int& a, int&b)
{
	a += b;
	b = a-b;
	a -=b;
}

void heapify(int arr[],int n,int i)
{
	int largest = i;
	int left = 2*i +1; // finding the left child
	int right = 2*i + 2; // finding the right child
	
	if ((arr[left] > arr[largest]) && (left < n))
		largest = left; //set largest pointer to left
	if ((arr[right] > arr[largest]) && (right < n))
		largest = right; //set largest pointer to right
	
	if(largest != i) //if parent is not still the largest
	{
		swap(arr[i],arr[largest]); //setting largest among the children as root/parent
		heapify(arr,n,largest); // heapify the remaining tree reference :
		/*https://www.programiz.com/dsa/heap-data-structure#:~:text=Heapify%20is%20the%20process%20of,by%20n%2F2%20%2D%201%20.
		*/
	}
	
}

void heapSort(int arr[] , int n)
{
	int k = n,j = n/2,m = n-1;
	while (m >=1){
	for(int i = j;i >=0 ; i--)
	{
		heapify(arr,k,i);
	}
	swap(arr[0],arr[m--]);
	k--;
	}
}

int main()
{
	int arr[8] = {0,1,2,2,1,3,0,0};
	cout<<endl;
	heapSort(arr,8);
	cout<<endl;
	for(int i = 0;i<8;i++)
		cout<<arr[i]<<" ";
	cout<<endl;
}