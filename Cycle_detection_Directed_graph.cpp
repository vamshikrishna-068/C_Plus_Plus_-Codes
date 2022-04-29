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
bool iscycle(int src, vector<vector<int>> &adj,vector<bool> &visited, vector<int> &stack){
	stack[src]=1;
	if(!visited[src]){
		visited[src]=true;
		for(auto i:adj[src]){
			cout<<"Busi"<<endl;
			if(!visited[i] && iscycle(i,adj,visited,stack)){
				return true;
			}
			if(stack[i]){
				return true;
			}
		}
	}
	stack[src]=0;
	return false;
}
int main(){	
	int n,m;cin>>n>>m;
	vector<vector<int>> adj(n);
	for(int i=0;i<m;i++)
	{
		int x,y;
		cin>>x>>y;
		adj[x].pb(y);
	}
	bool cycle=false;
	vector<int> stack(n,0);
	vector<bool> visited(n,false);
	for(int i=0;i<n;i++){
		if(!visited[i] && iscycle(i,adj,visited,stack)){
			cycle=true;
		}
	}
	if(cycle){
		cout<<"Cycle"<<endl;
	}
	else{
		cout<<"No cycle"<<endl;
	}
	return 0;
}