#include<iostream>
using namespace std;
int main()
{
	int arr[]={3,1,6,2,8,4};
	int n=6;
	for(int i=0;i<=n-2;i++)
	{
		int min=i;
		for(int j=i;j<=n-1;j++)
		{
			if(arr[min]>arr[j]) min=j;
		}
		int temp=arr[i];
		arr[i]=arr[min];
		arr[min]=temp;
	}
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
}