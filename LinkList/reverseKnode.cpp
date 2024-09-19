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
	Node* current=head;
	for(int i=1;i<arr.size();i++)
	{
		Node* temp=new Node(arr[i]);
		current->next=temp;
		current =temp;
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
Node* getKthNode(Node* temp, int k){
    
    k -= 1; 

    
    while(temp != NULL && k > 0){
        
        k--; 
        
       
        temp = temp -> next; 
    }
    
    // Return the Kth node
    return temp; 
}
Node* reverseKthNode(Node* head,int k)
{
	Node* temp=head;
	Node* nextNode=NULL;
	Node* prev=NULL;
	Node* kthnode;
	while(temp!=NULL)
	{
	
		Node* kthnode=getKthNode(temp,k);
		if(kthnode==NULL)
		{
			if(prev) prev->next=temp;
			break;
		}
	
		
		nextNode=kthnode->next;
		kthnode->next=NULL;
		reverse(temp);
		if(temp==head)
		{
			head=kthnode;
		}
		else{
			prev->next=kthnode;
		}
		prev=temp;
		temp=nextNode;
	}
	return head;
}
int main()
{
	vector<int>arr={1,2,3,4,5};
	Node* head=create(arr);
	head=reverseKthNode(head,2);
	
	print(head);
	cout<<"\n";
	
}