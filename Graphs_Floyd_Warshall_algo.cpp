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
	// int n,m;cin>>n>>m;
	vector<vector<int>> graph={
					{0,5,INF,10},
					{INF,0,3,INF},
					{INF,INF,0,1},
					{INF,INF,INF,0}
	};
	int n=graph.size();
	vector<vector<int>> dist=graph;
	for(int k=0;k<n;k++){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(dist[i][k]+dist[k][j] < dist[i][j]){
					dist[i][j]=dist[i][k]+dist[k][j];
				}
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(dist[i][j]==INF){
				cout<<"INF ";
			}
			else{
				cout<<dist[i][j]<<" ";
			}
		}
		cout<<endl;
	}
	return 0;
}