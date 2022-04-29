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
bool bipart;
void color(int u, int curr,vector<vector<int>> & adj,vector<bool> &visited, vector<int> &col){
	if(col[u]!=-1 && col[u]!=curr){
		bipart=false;
		return;
	}
	col[u]=curr;
	if(visited[u])
		return;
	visited[u]=true;
	for(auto i: adj[u]){
		color(i,curr xor 1,adj,visited,col); // sending alternative 1 and 0's
	}
}
int main(){
	bipart=true;
	int n,m;cin>>n>>m;
	vector<vector<int>> adj(n);
	vector<bool> visited(n,false);
	vi col(n,-1);
	for(int i=0;i<m;i++){
		int u,v;
		cin>>u>>v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	for(int i=0;i<n;i++){
		if(!visited[i]){
			color(i,0,adj,visited,col);
		}
	}
	if(bipart){
		cout<<"Graph is bipart"<<endl;
	}
	else{
		cout<<"Graph is not biparte"<<endl;
	}
	return 0;
}