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
vi adj[N];
bool vis[N];
int main(){
	for(int i=0;i<N;i++){
		vis[i]=0;
	}
	int n,m;
	cin>>n>>m;
	int x,y;
	for(int i=0;i<m;i++){
		int x,y;
		cin>>x>>y;
		adj[x].pb(y);
		adj[y].pb(x);
	}
	queue<int> q;
	q.push(1);
	vis[1]=1;
	while(!q.empty()){
		int n=q.front();
		cout<<n<<" ";
		q.pop();
		for(int u:adj[n]){
			if(!vis[u]){
			vis[u]=1;
			q.push(u);
		}
		}
	}
	return 0;
}