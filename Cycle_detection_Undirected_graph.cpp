// Cycle detection in Undirected Graph i.e if we visit the same node once 
// again then there will be a cycle
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
bool iscycle(int src,vector<vector<int>> &adj,vector<bool> visited, int parent){
	visited[src]=true;
	for(auto i:adj[src]){
		if(i!=parent){
			if(visited[i]){
				return true;
			}
			if(!visited[i] && iscycle(i,adj,visited,src)){
				return true;
			}
		}
	}
	return false;
}
int main(){
	int n,m;cin>>n>>m;
	vector<vector<int>> adj(n);
	for(int i=0;i<m;i++){
		int x,y;
		cin>>x>>y;
		adj[x].pb(y);
		adj[y].pb(x);
	}
	bool cycle=false;
	vector<bool> visited(n,false);
	for(int i=0;i<n;i++){
		if(!visited[i] && iscycle(i,adj,visited,-1)){
			cycle=true;
		}
	}
	if(cycle)
	{
	cout<<"Cycle"<<endl;
	}
else
	{
	cout<<"NO cycle"<<endl;
	}


	return 0;
}
// Test Case
// 4 3
// 0 1
// 1 2
// 2 0
//output:- Cycle

// test case-2
// 4 2
// 0 1
// 1 2
// output:-NO cycle