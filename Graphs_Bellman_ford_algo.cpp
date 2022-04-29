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
const int INF=1e9+2;
int main(){

	int n,m;cin>>n>>m;
	vector<vector<int>> edges;
	for(int i=0;i<m;i++){
		int u,v,w;cin>>u>>v>>w;
		edges.pb({u,v,w});
	}
	int src;cin>>src;
	vi dist(n,INF);
	dist[src]=0;
	bool cycle=false;
	for(int i=0;i<n-1;i++){
		for(auto e:edges){
			int u=e[0];
			int v=e[1];
			int w=e[2];
			if(dist[v]>w+dist[u]){
				cycle=true;
			}
			dist[v]=min(dist[v],w+dist[u]);
		}
	}
	for(auto i: dist){
		cout<<i<<" ";
	}
	cout<<endl;
	// if(cycle){   // some error 
	// 	cout<<"Cycle"<<endl;
	// }
	// else{
	// 	cout<<"Not a cycle"<<endl;
	// }
	return 0;
}