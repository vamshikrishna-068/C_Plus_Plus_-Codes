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
int get_components(int i,vector<vector<int>> &adj, vector<bool> &visited){
	if(visited[i]){
		return 0;
	}
	visited[i]=true;
	int ans=1;
	for(auto x: adj[i]){
		if(!visited[x]){
			ans+=get_components(x,adj,visited);
			visited[x]=true;
		}
	}
	return ans;
}
int main(){
	int n,m;cin>>n>>m;
	vector<vector<int>> adj(n);
	for(int i=0;i<m;i++){
		int x,y;cin>>x>>y;
		adj[x].pb(y);
		adj[y].pb(x);
	}
	vector<int> components;
	vector<bool> visited(n,false);
	for(int i=0;i<n;i++){
		if(!visited[i]){
			components.pb(get_components(i,adj,visited));
		}
	}
	// for(auto i: components){
	// 	cout<<i<<" ";
	// }
	// to choose a friend who is not in his connected component
	ll ans=0;
	for(auto i: components){
		ans+=i*(n-i);
	}
	cout<<ans/2<<endl;
	return 0;
}