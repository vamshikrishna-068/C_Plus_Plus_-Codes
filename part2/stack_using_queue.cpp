// method - I making push operation costly
// method - II making pop operation costly
#include <bits/stdc++.h>
using namespace std;
// method -  I
class stack_using_queue_push{
	int N;
	queue<int> q1;
	queue<int> q2;
public:
	stack_using_queue_push(){
		N=0;
	}
	void push(int val){
		q2.push(val);
		N++;
		while(!q1.empty()){
			q2.push(q1.front());
			q1.pop();

		}
		queue<int> temp=q1;
		q1=q2;
		q2=temp;
	}
	void pop(){
		q1.pop();
		N--;
	}
	int top(){
		return q1.front();
	}
	int size(){
		return N;
	}
};
// method - II
class stack_using_queue_pop{
	int N;
	queue<int> q1;
	queue<int> q2;
public:
	stack_using_queue_pop(){
		N=0;
	}
	void push(int val){
		q1.push(val);
		N++;
	}
	void pop(){
		if(q1.empty()){
			return;
		}
		while(q1.size()!=1){
			q2.push(q1.front());
			q1.pop();
		}
		q1.pop();
		N--;
		queue<int> temp=q1;
		q1=q2;
		q2=temp;
	}
	int top(){
		if(q1.empty()){
			return -1;
		}
		while(q1.size()!=1){
			q2.push(q1.front());
			q1.pop();
		}
		int ans=q1.front();
		q2.push(q1.front());
		q1.pop();
		queue<int> temp=q1;
		q1=q2;
		q2=temp;
		return ans;
	}
	int size(){
		return N;
	}
};
int main(){
	// method - I

	// stack_using_queue_push st;
	// st.push(1);
	// st.push(2);
	// st.push(3);
	// st.push(4);
	// cout<<st.top()<<endl;
	// st.pop();
	// cout<<st.top()<<endl;
	// method - II
	stack_using_queue_pop st1;
	st1.push(1);
	st1.push(2);
	st1.push(3);
	st1.push(4);
	cout<<st1.top()<<endl;
	st1.pop();
	cout<<st1.top()<<endl;
	cout<<st1.size()<<endl;
	return 0;
}