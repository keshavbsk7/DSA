#include<iostream>
#include<vector>  
using namespace std;
void merge(vector<int> &arr,int low,int mid,int high)
{
	vector<int>temp;
	int left=low;
	int right=mid+1;
	while(left<=mid&&right<=high)
	{
		if(arr[left]<=arr[right])
		{
			temp.push_back(arr[left]);
			left++;
		}
		else
		{
			temp.push_back(arr[right]);
			right++;
		}
	}
	while(left<=mid)
	{
		temp.push_back(arr[left]);
		left++;
	}
	while(right<=high)
	{
		temp.push_back(arr[right]);
		right++;
	}
	for(int i=low;i<=high;i++)
	{
		arr[i]=temp[i-low];
	}
}
void mergesort(int low,int high,vector<int> &arr)
{
	if(low==high) return;
	int mid=(low+high)/2;
	mergesort(low,mid,arr);
	mergesort(mid+1,high,arr);
	merge(arr,low,mid,high);
}
int main()
{
	vector<int> arr={3,1,2,4,1,5,6,2,4};
	mergesort(0,arr.size()-1,arr);
	for(auto i:arr)
	{
		cout<<i<<" ";
	}
	
}