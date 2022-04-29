#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define ff first
#define ss second
#define pii pair<int,int>
#define vii vector<pii>
#define ll long long
#define pb push_back
const int N=1e3+2,MOD=1e9+7;
const int INF=1e9+2;
int dp[N][N];
int Coinchange(vi &a, int n, int x){
	if(x==0){
		return 1;
	}
	if(x<0)
		return 0;
	if(n<=0)
		return 0;
	if(dp[n][x]!=-1){
		return dp[n][x];
	}
	dp[n][x]= Coinchange(a,n-1,x)+Coinchange(a,n,x-a[n-1]);
	return dp[n][x];
}
int main(){
	int n;cin>>n;
	vi a(n);
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			dp[i][j]=-1;
		}
	}
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int x;
	cin>>x;
	cout<<Coinchange(a,n,x);
	return 0;
}