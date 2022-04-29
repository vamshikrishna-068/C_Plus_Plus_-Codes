// merging two sorted linkedlists using normal and recursion
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
node* merge(node* &head1, node* head2){
	node* p1=head1;
	node* p2=head2;
	node* dummy=new node(-1);
	node* p3=dummy;
	while(p1!=NULL && p2!=NULL){
		if(p1->data<p2->data){
			p3->next=p1;
			p1=p1->next;
		}
		else{
			p3->next=p2;
			p2=p2->next;
		}
		p3=p3->next;
	}
	while(p1!=NULL){
		p3->next=p1;
		p1=p1->next;
		p3=p3->next;
	}
	while(p2!=NULL){
		p3->next=p2;
		p2=p2->next;
		p3=p3->next;
	}
	return dummy->next;
}
node* mergeRecursive(node* &head1, node* &head2){
	if(head1==NULL){
		return head2;
	}
	if(head2==NULL){
		return head1;
	}
	node* result;
	if(head1->data<head2->data){
		result=head1;
		result->next=mergeRecursive(head1->next,head2);
	}
	else{
		result=head2;
		result->next=mergeRecursive(head1,head2->next);
	}
	return result;
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
int main(){
	node* head1=NULL;
	node* head2=NULL;
	int a[]={1,4,5,7};
	int b[]={2,3,6};
	for(int i=0;i<4;i++){
		insertatTail(head1,a[i]);
	}
	for(int i=0;i<3;i++){
		insertatTail(head2,b[i]);
	}
	displaynode(head1);
	displaynode(head2);
	// node* newhead=merge(head1,head2);
	// displaynode(newhead);
	node* newhead=mergeRecursive(head1,head2);
	displaynode(newhead);	
	return 0;
}