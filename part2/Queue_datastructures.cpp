// queue implementation using array
// queue implementation using linked list
#include <bits/stdc++.h>
using namespace std;
#define n1 100
class queue_using_array{

	int* arr;
	int front;
	int back;
	public:
	queue_using_array(){
		arr=new int[n1];
		front=-1;
		back=-1;
	}
	void push(int x){
		if(back==n1-1){
			cout<<"Queue overflow"<<endl;
			return;
		}
		back++;
		arr[back]=x;
		if(front==-1){
			front++;
		}
	}
	void pop(){
		if(front==-1 || front>back){
			cout<<"No element in queue"<<endl;
			return;
		}
		front++;
	}
	int peek(){
		if(front==-1 || front>back){
			cout<<"No element in queue"<<endl;
			return -1;
		}
		return arr[front];	
	}
	bool empty(){
		if(front==-1 || front>back){
			return true;
		}
		return false;
	}
};
class node{
public:
	int data;
	node* next;

	node(int val){
		data=val;
		next=NULL;
	}

};
class queue_using_linkedlist{
	node* front;
	node* back;
public:
	queue_using_linkedlist(){
		front=NULL;
		back=NULL;
	}
	void push(int val){
		node* n=new node(val);
		if(front==NULL){
			front=n;
			back=n;
			return;
		}
		back->next=n;
		back=n;

	}
	void pop(){
		if(front==NULL){
			cout<<"No element in queue"<<endl;
			return;
		}
		node* todelete=front;
		front=front->next;
		delete todelete;
	}
	int peek(){
		if(front==NULL){
			cout<<"No element to pop"<<endl;
			return -1;
		}
		return front->data;
	}
	bool empty(){
		if(front==NULL){
			return true;
		}
		else
			return false;	
	}
};
int main(){
	// Queue using array
	// queue_using_array q;
	// q.push(1);
	// q.push(2);
	// q.push(3);
	// q.push(4);
	// q.push(5);
	// cout<<q.peek()<<endl;
	// q.pop();
	// cout<<q.peek()<<endl;
	// q.pop();
	// cout<<q.peek()<<endl;
	// q.pop();
	// q.pop();
	// q.pop();
	// cout<<q.empty()<<endl;

// *******************************************************************//
	// Queue using linked list
	queue_using_linkedlist ql;
	ql.push(1);
	ql.push(2);
	ql.push(3);
	ql.push(4);
	ql.push(5);
	cout<<ql.peek()<<endl;
	ql.pop();
	cout<<ql.peek()<<endl;
	ql.pop();
	cout<<ql.peek()<<endl;
	ql.pop();
	cout<<ql.peek()<<endl;
	ql.pop();
	ql.pop();
	cout<<ql.empty()<<endl;
	return 0;
}