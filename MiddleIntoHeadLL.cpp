#include <bits/stdc++.h>
using namespace std;
class Node{
	public:
		int data;
		Node* next;
};
void frontadd(Node**head,int data){
	Node*temp=new Node();
	temp->data=data;
	temp->next=*head;
	*head=temp;
}
void appendLL(Node**head,int data){
	Node*temp=new Node();
	temp->data=data;
	temp->next=NULL;
	if(*head==NULL){
		*head=temp;
		return;
	}
	Node*curr=*head;
	while(curr->next)
	curr=curr->next;
	
	curr->next=temp;
}
void printLL(Node*head){
	while(head){
		cout<<head->data<<" ";
		head=head->next;
	}
	cout<<endl;
}
void middleTOhead(Node**head){
	if(*head==NULL || (*head)->next==NULL || (*head)->next->next==NULL)
	return;
	Node*slow=*head,*fast=*head,*prev=NULL;
	while(fast && fast->next && fast->next->next){
		prev=slow;
		slow=slow->next;
		fast=fast->next->next;
	}
	prev->next=slow->next;
	slow->next=*head;
	*head=slow;
}
int main(){
	Node*head=NULL;
     for(int i=1;i<=11;i++)
     appendLL(&head,i*10);
	middleTOhead(&head);
	printLL(head);
	return 0;
}
