#include<iostream>
#include<vector>
using namespace std;
void swap(int i,int j,vector<int> &arr)
{
	int temp=arr[i];
	arr[i]=arr[j];
	arr[j]=temp;
}
int  qs(int low,int high,vector<int> &arr)
{
	int pivot=arr[low];
	int i=low;
	int j=high;
	while(i<j)
	{
		while(arr[i]<=pivot&&i<=high-1)
		{
			i++;
		}
		while(arr[j]>pivot && j>=low+1)
		{
			j--;
		}
		if(i<j) swap(i,j,arr);
			
	}
	swap(low,j,arr);
	return j;
	
}
void quicksort(int low,int high,vector<int> &arr)
{
	if(low<high){
	
	int index=qs(low,high,arr);
	quicksort(low,index-1,arr);
	quicksort(index+1,high,arr);
	}
}
int main()
{
	vector<int>arr={4,6,2,5,7,9,1,3};
	quicksort(0,arr.size()-1,arr);
	for(auto i:arr)
	{
		cout<<i<<" ";
	}
	return 0;
}