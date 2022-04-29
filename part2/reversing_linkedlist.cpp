// Basic linked list operations
// reversing the linked list using normal and recursive method
// reversing k-nodes
// making cycle, detecting cycle and removingcycle(floyds or Hare-Tort.algo)
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
void insertatTail(node* &head,int  val){
	node* n=new node(val);
	if(head==NULL){
		head=n;
		return;
	}
	node* temp=head;
	while(temp->next!=NULL){
		temp=temp->next;
	}
	temp->next=n;
}
void insertAtHead(node* &head,int val){
	node* n=new node(val);
	n->next=head;
	head=n;
}
bool search(node* head,int key){
	node* temp=head;
	while(temp!=NULL){
		if(temp->data==key){
			return true;
		}
		temp=temp->next;
	}
	return false;
}
void displaynode(node* head)
{
	node* temp=head;
	while(temp!=NULL){
		cout<<temp->data<<"->";
		temp=temp->next;
	}
	cout<<"NULL"<<endl;
}
void deleteatHead(node* &head){
	node* todelete=head;
	head=head->next;
	delete todelete;
}
void deletenode(node* &head, int key){
	if(head==NULL){
		return;
	}
	if(head->next==NULL){
		deleteatHead(head);
		return;
	}
	node* temp=head;
	while(temp->next->data!=key){
		temp=temp->next;
	}
	node* todelete=temp->next;
	temp->next=temp->next->next;
	delete todelete;
}
void reverse(node* &head){
	node* prevptr=NULL;
	node* curptr=head;
	node* nextptr;
	while(curptr!=NULL){
	nextptr=curptr->next;
	curptr->next=prevptr;
	prevptr=curptr;
	curptr=nextptr;
	}
	head= prevptr;
}
node* RecursiveReverse(node* &head){
	if(head==NULL || head->next==NULL){
		return head;
	}
	node* newhead=RecursiveReverse(head->next);
	head->next->next=head;
	head->next=NULL;
	return newhead;
}
node* reversek(node* head,int k){
	node* prevptr=NULL;
	node* curptr=head;
	node* nextptr;
	int count=0;
	while(curptr!=NULL && count<k){
		nextptr=curptr->next;
		curptr->next=prevptr;
		prevptr=curptr;
		curptr=nextptr;
		count++;	
	}
	if(nextptr!=NULL){
		head->next=reversek(nextptr,k);
	}
	return prevptr;
}
void makecycle(node* &head, int pos){
	node* startnode=NULL;
	node* temp=head;
	int count=1;
	while(temp->next!=NULL){
		if(count==pos){
			startnode=temp;
		}
		temp=temp->next;
		count++;
	}
	temp->next=startnode;
}
bool detectCycle(node* &head){
	node* slow=head;
	node* fast=head;
	while(fast!=NULL && fast->next!=NULL){
		slow=slow->next;
		fast=fast->next->next;

		if(fast==slow){
			return true;
		}
	}
	return false;
}
void removecycle(node* &head){
	node* slow=head;
	node* fast=head;
	do{
		slow=slow->next;
		fast=fast->next->next;

	}while(slow!=fast);
	fast=head;
	while(slow->next!=fast->next){
		slow=slow->next;
		fast=fast->next;
	}
	slow->next=NULL;
}
int main(){
	node* head=NULL;
	insertatTail(head,1);
	insertatTail(head,2);
	insertatTail(head,3);
	insertatTail(head,5);
	insertatTail(head,6);
	// displaynode(head);
	insertAtHead(head,4);
	// displaynode(head);
	// cout<<search(head,2)<<endl;
	// cout<<search(head,5)<<endl;
	// deletenode(head,3);
	// deleteatHead(head);
	reverse(head);
	// displaynode(head);	
	node* newhead=RecursiveReverse(head);
	// displaynode(newhead);	
	node* busi=reversek(newhead,2);
	displaynode(busi);
	newhead=reversek(busi,2);
	int pos=3;
	makecycle(newhead,pos);
	cout<<detectCycle(newhead)<<endl;
	// displaynode(newhead);
	removecycle(newhead);
	cout<<detectCycle(newhead)<<endl;
	displaynode(newhead);
	return 0;
}