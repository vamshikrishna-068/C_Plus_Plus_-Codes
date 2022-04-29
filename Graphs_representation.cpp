// 
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
vi adj[N]; // is same as vector<vector<int>> (n);
int main(){
	// int n,m;
	// cin>>n>>m;
	// vector<vector<int>> adjm(n+1,vi(n+1,0))
	// for(int i=0;i<m;i++){
	// 	int x,y;
	// 	cin>>x>>y;
	// 	adjm[x][y]=1;
	// 	adjm[y][x]=1;
	// }
	// cout<<"Adjacency matrix of above graph is given by: "<<endl;
	// for(int i=1;i<n+1;i++){
	// 	for(int j=1;j<n+1;j++){
	// 		cout<<adjm[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int x,y;
		cin>>x>>y;
		adj[x].pb(y);
		adj[y].pb(x);
	}
	cout<<"adjacency list of the above graph is given by: "<<endl;
	for(int i=1;i<n+1;i++){
		cout<<i<<"-> ";
		for(int x:adj[i]){
			cout<<x<<" ";
		}
		cout<<endl;
	}
	return 0;
}