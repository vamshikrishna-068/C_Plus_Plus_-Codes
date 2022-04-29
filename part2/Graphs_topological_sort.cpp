// Topological Sort:-in directed graph a->b:: a should be printed first 
#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define ff first
#define ss second
#define pii pair<int,int>
#define vii vector<pii>
#define ll long long
#define pb push_back
const int N=1e5+2,MOD=1e9+7;
int main(){
	int n,m;
	cin>>n>>m;
	int cnt=0;
	vector<vector<int>>adj(n);
	vi indegree(n,0);
	for(int i=0;i<m;i++){
		int x,y;
		cin>>x>>y;
		adj[x].pb(y);
		indegree[y]++;
	}
	queue<int> q;
	for(int i=0;i<n;i++){
		if(indegree[i]==0){
			q.push(i);
		}
	}
	while(!q.empty()){
		cnt++;
		int x=q.front();
		q.pop();
		cout<<x<<" ";
		for(auto i: adj[x]){
			indegree[i]--;
			if(indegree[i]==0){
				q.push(i);
			}
		}
	}
	return 0;
}