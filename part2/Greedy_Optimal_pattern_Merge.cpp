// we are given n files with their computational times and have to merge two-
// -files at a time and result will be a new file with new computational time
// continue to do so such that final answer will be minimum
// Eg:- [5 1 1 2] , ans=[6 1 2], ans=[7 2]=ans=[8] final_ans=6+7+9=22
//  if we sort it [1 1 2 5] ans=[2 2 5], ans=[4 5] ,ans=[9], final_ans=2+4+5=11<22
#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define ff first
#define ss second
#define pii pair<int,int>
#define vii vector<pii>
int main(){
	int n;
	cin>>n;
	vi a(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	priority_queue<int,vector<int>,greater<int>> minheap;
	for(int i=0;i<n;i++){
		minheap.push(a[i]);
	}
	int ans=0;
	while(minheap.size()>1){
		int e1=minheap.top();
		minheap.pop();
		int e2=minheap.top();
		minheap.pop();
		int e3=e1+e2;
		ans+=e3;
		minheap.push(e3);
	}
	cout<<ans<<endl;
	return 0;
}