#include<stdio.h>
#include<stdlib.h>

void swap (int* a, int* b)
{
	*a += *b;
	*b = *a - *b;
	*a -= *b;
}
void reverse(int arr[] , int n)
{
	int i = 0,j =n-1;
	while(i<j)
	{
		swap(&arr[i],&arr[j]);
		i++;
		j--;
	}
}
int main()
{
	int testcases,n,*arr;
	scanf("%d",&testcases);
	while(testcases -- ){
	scanf("%d",&n);
    *arr = (int*)malloc(sizeof(int)*n);
	for(int i = 0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	printf("\n");
	for(int i = 0;i<n;i++)
		printf("%d ",arr[i]);	
	reverse(arr,n);
	printf("\n");
	for(int i = 0;i<n;i++)
		printf("%d ",arr[i]);
	printf("\n");
	}
	return 0;
}