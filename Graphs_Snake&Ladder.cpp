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
	int ladders,snake;
	cin>>ladders;
	map<int,int> lad;
	map<int,int> snk;
	for(int i=0;i<ladders;i++){
		int u,v;
		cin>>u>>v;
		lad[u]=v;
	}
	cin>>snake;
	for(int i=0;i<snake;i++){
		int u,v;cin>>u>>v;
		snk[u]=v;
	}
	int moves=0;
	queue<int> q;
	q.push(1);
	bool found=false;
	vi vis(101,0);
	vis[1]=0;
	while(!q.empty() && !found){
		int sz=q.size();
		while(sz--){
			int t=q.front();
			q.pop();
			for(int dice=1;dice<=6;dice++){
				if(t+dice==100){
					found=true;
				}
				if(t+dice<=100 && lad[t+dice] && !vis[lad[t+dice]]){
					vis[lad[t+dice]]=true;
					if(lad[t+dice]==100){
						found=true;
					}
					q.push(lad[t+dice]);
				}
				else if(t+dice<=100 && snk[t+dice] && !vis[snk[t+dice]]){
					vis[snk[t+dice]]=true;
						if(snk[t+dice]==100){
							found=true;
						}
						q.push(snk[t+dice]);
				}
				else if(t+dice<=100 && !vis[t+dice] && !snk[t+dice] && !lad[t+dice]){
					vis[t+dice]=true;
					q.push(t+dice);
				}


			}
		}
		moves++;
	}
	if(found){
		cout<<moves<<endl;
	}
	else{
		cout<<"-1"<<endl;
	}
	return 0;
}