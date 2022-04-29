// stack implementation
// reversing a sentence using stack stl
// to take space separated string as input use ****getline(cin,s)****
// reverse a stack in itself using recursion
#include <bits/stdc++.h>
using namespace std;
#define n 100
class stack_datastructure{
	int* arr;
	int top;
public:
	stack_datastructure(){
		arr=new int[n];
		top=-1;
		}
		void push(int x){
			if(top==n-1){
				cout<<"stack overflow"<<endl;
				return;
			}
			top++;
			arr[top]=x;
		}
		void pop(){
			if(top==-1){
				cout<<"no element to pop"<<endl;
				return;
			}
			top--;
		}
		int Top(){
			if(top==-1){
				cout<<"no element in stack"<<endl;
				return -1;
			}
			return arr[top];
		}
		bool empty(){
			return top==-1;
		}
};
void reverseSentence(string s){
	stack<string> st;
	int last=-1;
	string a;
	int i;
	for(i=0;i<s.length();i++){
		if(s[i]==' '){
			a=s.substr(last+1,i-last-1);
			st.push(a);
			last=i;
		}
	}
	a=s.substr(last+1,i-last-1);
	st.push(a);
	while(!st.empty()){
		cout<<st.top()<<" ";
		st.pop();
	}

}
void insertAtBottom(stack<int> &st, int ele){
	if(st.empty()){
		st.push(ele);
		return;
	}
	int topele=st.top();
	st.pop();
	insertAtBottom(st,ele);
	st.push(topele);
}
void reverseStack(stack<int> &st){
	if(st.empty()){
		return ;
	}
	int ele=st.top();
	st.pop();
	reverseStack(st);
	insertAtBottom(st,ele);
}
int main(){
	// stack_datastructure st;
	// st.push(1);
	// st.push(2);
	// st.push(3);
	// st.push(4);
	// cout<<st.Top()<<endl;
	// st.pop();
	// cout<<st.Top()<<endl;
	// st.pop();
	// st.pop();
	// st.pop();
	// cout<<"checking empty"<<st.empty()<<endl;
	// // stack<int> s;
	// string s="Hey, how are you doing?";
	// // getline(cin,s);
	// reverseSentence(s);
	stack<int> st;
	st.push(1);
	st.push(2);
	st.push(3);
	st.push(4);
	st.push(5);
	reverseStack(st);
	while(!st.empty()){
		cout<<st.top()<<" ";
		st.pop();
	
	}
	cout<<endl;
		return 0;
}