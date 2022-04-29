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
vi parent(N);
vi sz(N);
void make_set(int u){
	parent[u]=u;
	sz[u]=1;
}
int find_set(int u){
	if(u==parent[u]){
		return u;
	}
	return parent[u]=find_set(parent[u]);
}
void union_sets(int u, int v){
	u=find_set(u);
	v=find_set(v);
	if(u!=v){
		if(sz[u]<sz[v])
			swap(u,v);
		parent[v]=u;
		sz[u]+=sz[v];
	}
}
int main(){
	for(int i=0;i<N;i++){
		make_set(i);
	}
	int n,m;
	cin>>n>>m;
	vector<vector<int>> edges;
	for(int i=0;i<m;i++){
		int u,v,w;cin>>u>>v>>w;
		edges.pb({u,v,w});
	}
	sort(edges.begin(),edges.end());
	int cost=0;
	for(auto i:edges){
		int w=i[0];
		int u=i[1];
		int v=i[2];
		int a=find_set(u);
		int b=find_set(v);
		if(a==b){
			continue;
		}
		else{
			cout<<u<<" "<<v<<endl;
			cost+=w;
			union_sets(u,v);
		}
	}
	cout<<cost<<endl;
	return 0;
}