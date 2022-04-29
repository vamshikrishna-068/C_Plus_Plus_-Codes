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
	vector<int> dist(n+1,INF);
	vector<vector<pii>> graph(n+1);
	for(int i=0;i<m;i++){
		int u,v,w;cin>>u>>v>>w;
		graph[u].pb({v,w});
		graph[v].pb({u,w});
	}
	int source;cin>>source;
	dist[source]=0;
	set<pii> s;
	s.insert({0,source}); // {wgt,vertex}
	while(!s.empty()){
		auto x=*(s.begin());
		s.erase(x);
		for(auto i: graph[x.ss]){
			if(dist[i.ff]>dist[x.ss]+i.ss){
				s.erase({dist[i.ff],i.ff});
				dist[i.ff]=dist[x.ss]+i.ss;
				s.insert({dist[i.ff],i.ff});
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(dist[i]<INF){
			cout<<dist[i]<<" ";
		}
		else{
			cout<<"-1"<<" ";
		}
	}
	return 0;
}