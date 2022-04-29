// circular linked list basics
#include <bits/stdc++.h>
using namespace std;
class node{
public:
	int data;
	node* next;

	node(int val){
		data=val;
		next=NULL;
	}
};
void insertatHead(node* &head, int val){
	node* n=new node(val);
	if(head==NULL){
		head=n;
		n->next=head;
		return;
	}
	node* temp=head;
	while(temp->next!=head){
		temp=temp->next;
	}
	temp->next=n;
	n->next=head;
	head=n;

}
void deletion(node* &head, int pos){
	if(pos==1){
		node* todelete=head;
		node* temp=head;
		while(temp->next!=head){
			temp=temp->next;
		}
		temp->next=head->next;
		head=head->next;
		delete todelete;

		return;
	}
	node* temp=head;
	int count=1;
	while(count!=pos-1){
		temp=temp->next;
		count++;
	}
	node* todelete=temp->next;
	temp->next=temp->next->next;
	delete todelete;
}
void display(node* head){
	node* temp=head;
	do{
		cout<<temp->data<<"->";
		temp=temp->next;
	}while(temp!=head);
	cout<<"NULL"<<endl;
}
void inseratTail(node* &head, int val){
	if(head==NULL){
		insertatHead(head,val);
		return;
	}
	node* n=new node(val);
	node* temp=head;
	while(temp->next!=head){
		temp=temp->next;
	}
	temp->next=n;
	n->next=head;
}
int main(){
	node* head=NULL;
	inseratTail(head,1);
	inseratTail(head,2);
	inseratTail(head,3);
	inseratTail(head,4);
	display(head);
	insertatHead(head,5);
	display(head);
	deletion(head,1);
	display(head);
	return 0;
}