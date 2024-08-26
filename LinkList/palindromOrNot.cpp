#include<iostream>
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
void create(Node* head,int data)
{
	Node* temp=new Node(data);
	Node* current = head;
    
   
    while (current->next != nullptr) {
        current = current->next;
    }
    current->next = temp;
   
}
Node* reverse(Node* head)
{
	if(head==NULL||head->next==NULL)
	return head;
	Node* newHead=reverse(head->next);
	Node* front=head->next;
	front->next=head;
	head->next=NULL;
	return newHead;
}
bool checkPalindrome(Node* head)
{
	Node* fast=head;
	Node* slow=head;
	while(fast->next!=NULL&&fast->next->next!=NULL)
	{
		fast=fast->next->next;
		slow=slow->next;
	}
	Node* s1=head;
	Node* s2=reverse(slow->next);
	while(s2!=NULL)
	{
		if(s1->data!=s2->data)return false;
		s1=s1->next;
		s2=s2->next;
	}
	return true;
}
int main()
{
	int arr[5]={1,2,3,2,0};
	
	Node *head=new Node(arr[0]);
	
	for(int i=1;i<5;i++)
	{
		create(head,arr[i]);
	}
	cout<<checkPalindrome(head);
	
}