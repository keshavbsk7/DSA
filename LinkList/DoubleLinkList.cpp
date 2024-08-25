#include<iostream>
#include<vector>
using namespace std;
class Node
{
	public:
	int data;
	Node* next;
	Node* back;
	Node(int data)
	{
		this->data=data;
		this->next=nullptr;
		this->back=nullptr;
	}
	Node(int data,Node* next1,Node* back1)
	{
		this->data=data;
		this->next=next1;
		this->back=back1;
	}
};
Node* create(vector<int> arr)
{
	Node* head=new Node(arr[0]);
	Node* prev=head;
	for(int i=1;i<arr.size();i++)
	{
		Node* temp=new Node(arr[i],nullptr,prev);
		prev->next=temp;
		prev=temp;
	}
	return head;
}
Node* deletehead(Node* head)
{
	if(head==NULL||head->next==NULL)
	{
		return NULL;
	}
	Node* prev=head;
	head=head->next;
	head->back=nullptr;
	prev->next=nullptr;
	delete prev;
	return head;
}
Node* deletetail(Node* head)
{
	if(head==NULL||head->next==NULL)
	{
		return NULL;
	}
	Node* temp=head;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	Node* prev=temp->back;
	prev->next=nullptr;
	temp->back=nullptr;
	delete temp;
	return head;
}
Node* deleteValnode(Node* head,int val)
{
	
	if(head==NULL||head->next==NULL)
	{
		return NULL;
	}
	if(head->data==val)
	{
		return deletehead(head);
	}
	else
	{
		Node* temp=head;
		while(temp->data!=val)
		{
			temp=temp->next;
		}
		if(temp->back==NULL&&temp->next==NULL)
		{
			delete temp;
			return NULL;
		}
		else if(temp->next==NULL){
			Node* prev=temp->back;
			prev->next=temp->next;
			delete temp;
			return head;
		}
		Node* prev=temp->back;
		prev->next=temp->next;
		temp->next->back=prev;
		temp->back=nullptr;
		temp->next=nullptr;
		delete temp;
		
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
int main()
{
	vector<int>arr={1,2,3,4,5};
	Node* head=create(arr);
	for(auto i:arr){
	
	head=deleteValnode(head,i);
	print(head);
	cout<<"\n";
	}
}
    