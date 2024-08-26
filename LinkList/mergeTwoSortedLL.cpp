#include<iostream>
#include<vector>
using namespace std;
class Node
{
	public:
	int data;
	Node* next;
	Node(int data)
	{
		this->data=data;
		this->next=nullptr;
	}
	Node(int data,Node* node)
	{
		this->data=data;
		this->next=node;
	}
};
Node* create(vector<int> arr)
{
	Node* head=new Node(arr[0]);
	Node* temp=head;
	for(int i=1;i<arr.size();i++)
	{
		Node* node=new Node(arr[i]);
		temp->next=node;
		temp=temp->next;
	}
	return head;
}
void print(Node* head)
{
	while(head!=NULL)
	{
		cout<<head->data<<" ";
		head=head->next;
	}
}
Node* merge(Node* h1,Node* h2)
{
	Node* dummy=new Node(-1);
	Node* t1=h1;
	Node* t2=h2;
	Node* temp=dummy;
	while(t1!=NULL&& t2!=NULL)
	{
		if(t1->data<t2->data)
		{
			temp->next=t1;
			temp=t1;
			t1=t1->next;
			
		}
		else
		{
			temp->next=t2;
			temp=t2;
			t2=t2->next;
		}
	}
	if(t1) temp->next=t1;
	else temp->next=t2;
	
	return dummy->next;
}
int main()
{
	vector<int>arr1={2,4,6,8,10};
	vector<int>arr2={1,3,5,7,9};
	Node* h1=create(arr1);
	Node* h2=create(arr2);
	Node* head=merge(h1,h2);
	print(head);
	cout<<"\n";
	
}