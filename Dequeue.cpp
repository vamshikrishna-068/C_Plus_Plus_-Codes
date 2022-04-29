// 1. dequeue=stack+queue
// 2. sliding window maximum
#include <bits/stdc++.h>
using namespace std;
int main(){
	// 1.
	// deque<int> q;
	// q.push_back(1);
	// q.push_back(2);
	// q.push_front(3);
	// q.push_front(4);
	// for(auto i: q)
	// 	cout<<i<<endl;
	// cout<<endl;
	// q.pop_back();
	// q.pop_front();
	// for(auto i: q)
	// 	cout<<i<<endl;
	// cout<<endl;
	// cout<<q.size()<<endl;

	// 2.
	int n,k;
	cin>>n>>k;
	vector<int> a(n);
	// cin>>A;
	for(auto &i : a)
		cin>>i;
	deque<int> q;
	vector<int> ans;
	for(int i=0;i<k;i++){
		while(!q.empty() && a[q.back()]<a[i]){
			q.pop_back();
		}
		q.push_back(i);
	}
	ans.push_back(a[q.front()]);
	for(int i=k;i<n;i++){
		if(q.front()==i-k){
			q.pop_front();
		}
		while(!q.empty() && a[q.back()]<a[i]){
			q.pop_back();
		}
		q.push_back(i);
		ans.push_back(a[q.front()]);

	}
	for(auto i: ans){
		cout<<i<<" ";
	}
	return 0;
}