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
bool vis[N];
vi adj[N];
void dfs(int n){
	vis[n]=1;
	cout<<n<<" ";
	for(int u: adj[n]){
		if(!vis[u]){
			dfs(u);
		}
	}
}
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=0;i<=n;i++){
		vis[i]=0;
	}
	for(int i=0;i<m;i++)
{
	int x,y;
	cin>>x>>y;
	adj[x].pb(y);
	adj[y].pb(x);
}
	dfs(1);
	return 0;
}
// 7 7
// 1 2
// 1 3
// 2 4
// 2 5
// 2 6
// 2 7
// 7 3