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
Node* insertOnIndex(Node* head,int data,int k)
{
	if(head==NULL)
	{
		if(k==1) return new Node(data);
		else return head;
	}
	if(k==1)
	{
		return new Node(data,head);
	}
	int cnt=0;
	Node* temp=head;
	while(temp!=NULL)
	{
		cnt++;
		if(cnt==(k-1))
		{
		
		Node* current=new Node(data,temp->next);
		temp->next=current;
		break;
		}
		temp=temp->next;
	}
	return head;
}
Node* insertOnEl(Node* head,int data,int el)
{
	if(head==NULL)
	{
	return NULL;
	}
	if(head->data==el)
	{
		return new Node(data,head);
	}
	Node* temp=head;
	while(temp->next!=NULL)
	{
		
		if(temp->data==el)
		{
		
		Node* current=new Node(data,temp->next);
		temp->next=current;
		break;
		}
		temp=temp->next;
	}
	return head;
}
int main()
{
	int arr[5]={9,2,0,7,5};
	
	Node *head=new Node(arr[0]);
	
	for(int i=1;i<5;i++)
	{
		create(head,arr[i]);
	}
	head=insertOnEl(head,100,7);
	Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
}