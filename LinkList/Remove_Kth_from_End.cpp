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
Node* remove_kth_from_end(Node* head,int k)
{
	Node* fast=head;
	Node* slow=head;
	for(int i=0;i<k;i++)
	{
		fast=fast->next;
	}
	if(fast==NULL) return head->next;
	while(fast->next!=NULL){
		fast=fast->next;
		slow=slow->next;
	}
	Node* deletnode=slow->next;
	slow->next=slow->next->next;
	free(deletnode);
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
	head=remove_kth_from_end(head,1);
	Node* current=head;
	 while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
}