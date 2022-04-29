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
		int x,y;
		cin>>x>>y;
		edges.pb({x,y});
	}
	bool cycle=false;
	for(auto i: edges){
		int u=i[0];
		int v=i[1];
		int x=find_set(u);
		int y=find_set(v);
		if(x==y){
			cycle=true;
		}
		else{
			union_sets(u,v);
		}
	}
	if(cycle){
		cout<<"Cycle"<<endl;
	}
	else{
		cout<<"No Cycle"<<endl;
	}
	return 0;
}