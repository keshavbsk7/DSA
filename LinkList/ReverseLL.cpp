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
	Node* temp=head;
	Node* prev=NULL;
		Node* front=NULL;
	while(temp!=NULL)
	{
		front=temp->next;
		temp->next=prev;
		prev=temp;
		temp=front;	
	}
	
	return prev;
}
Node* RecReverse(Node* head)
{
	if(head==NULL||head->next==NULL)
	return head;
	Node* newHead=RecReverse(head->next);
	Node* front=head->next;
	front->next=head;
	head->next=NULL;
	return newHead;
}
int main()
{
	int arr[5]={9,2,0,7,5};
	
	Node *head=new Node(arr[0]);
	
	for(int i=1;i<5;i++)
	{
		create(head,arr[i]);
	}
	head=RecReverse(head);
	Node* current=head;
	 while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
}