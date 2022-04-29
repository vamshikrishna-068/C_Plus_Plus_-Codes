// put even positioned nodes after odd positioned nodes
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
void evenafterOdd(node* &head){
	node* odd=head;
	node* even=head->next;
	node* evenstart=even;
	while(even->next!=NULL && odd->next!=NULL){
		odd->next=even->next;
		odd=odd->next;
		even->next=odd->next;
		even=even->next;
		if(even==NULL){
			break;
		}
	}
	odd->next=evenstart;
	// if(odd->next!=NULL){
	// 	even->next=NULL;
	// }
}
int main(){
	node* head=NULL;
	insertatTail(head,1);
	insertatTail(head,2);
	insertatTail(head,3);
	insertatTail(head,4);
	insertatTail(head,5);
	insertatTail(head,6);
	displaynode(head);
	evenafterOdd(head);
	displaynode(head);
	return 0;
}