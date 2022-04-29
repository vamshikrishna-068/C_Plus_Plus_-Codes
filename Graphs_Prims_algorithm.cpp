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
vector<vector<int>> g[N];
int cost=0;
int n,m;
vector<int> dist(N),parent(N);
vector<bool> vis(N,false);
void primsMST(int source){
	for(int i=0;i<n;i++){
		dist[i]=INF;
	}
	set<vector<int>> s; // {w,v}
	dist[source]=0;
	s.insert({0,source});
	while(!s.empty()){
		auto x=*(s.begin());
		s.erase(x);
		vis[x[1]]=true;
		int u=x[1];
		int v=parent[x[1]];
		int w=x[0];
		cout<<u<<" "<<v<<" "<<w<<endl;
		cost+=w;
		for(auto it: g[x[1]]){
			if(vis[it[0]]){
				continue;
			}
			if(dist[it[0]]>it[1]){
				s.erase({dist[it[0]],it[0]});
				dist[it[0]]=it[1];
				s.insert({dist[it[0]],it[0]});
				parent[it[0]]=x[1];
			}
		}

	}

}
int main(){

	cin>>n>>m;
	for(int i=0;i<m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		g[u].pb({v,w});
		g[v].pb({u,w});
	}
	primsMST(0);
	cout<<cost<<endl;
	return 0;
}