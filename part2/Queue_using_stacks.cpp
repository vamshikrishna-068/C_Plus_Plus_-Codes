#include <bits/stdc++.h>
using namespace std;

class queue_datastructure{
	stack<int> s1;
	stack<int> s2;
public:
	void push(int val){
		s1.push(val);
	}
	int pop(){
		if(s1.empty() && s2.empty()){
			cout<<"Queue is empty"<<endl;
			return -1;
		}
		if(s2.empty()){
			while(!s1.empty()){
				s2.push(s1.top());
				s1.pop();
			}
		}
		int topval=s2.top();
		s2.pop();
		return topval;
	}
	bool empty(){
		if(s1.empty() && s2.empty())
			return true;
		return false;
	}
};
class queue_using_recursive{
	stack<int> s1;
public:
	void push(int val){
		s1.push(val);
	}
	int pop(){
		if(s1.empty()){
			cout<<"Queue is empty"<<endl;
			return -1;
		}
		int x=s1.top();
		s1.pop();
		if(s1.empty()){
			return x;
		}
		int item = pop();
		s1.push(x);
		return item;
	}
	void print(){
		while(!s1.empty()){
			cout<<s1.top()<<" ";
			s1.pop();
		}
		cout<<endl;
	}
	bool empty(){
		if(s1.empty())
			return true;
		return false;
	}
};
int main(){
	// queue_datastructure q;
	// q.push(1);
	// q.push(2);
	// q.push(3);
	// q.push(4);
	// cout<<q.pop()<<endl;
	// q.push(5);
	// cout<<q.pop()<<endl;
	// cout<<q.pop()<<endl;
	// cout<<q.pop()<<endl;
	// cout<<q.pop()<<endl;
	// cout<<q.empty()<<endl;
	queue_using_recursive q1;
	q1.push(1);
	q1.push(2);
	q1.push(3);
	q1.push(4);
	q1.push(5);
	// q1.print();
	cout<<"empty"<<q1.empty()<<endl;
	cout<<"Popped "<<q1.pop()<<endl;
	cout<<"Popped "<<q1.pop()<<endl;
	q1.print();
	return 0;
}