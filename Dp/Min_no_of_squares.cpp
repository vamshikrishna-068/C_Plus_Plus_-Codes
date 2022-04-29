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
int dp[N];
int Minsquare(int n){
	if(n==1 || n==2 || n==3 || n==0){
		return n;
	}
	if(dp[n]!=MOD){
		return dp[n];
	}
	for(int i=1;i*i<=n;i++){
		dp[n]=min(dp[n],1+Minsquare(n-i*i));
	}
	return dp[n];
}
int main(){
	int n;cin>>n;
	for(int i=0;i< N;i++){
		dp[i]=MOD;
	}
	cout<<Minsquare(n)<<endl;
	// for(int i=0;i<n;i++){
	// 	cout<<dp[i]<<" ";
	// }
	return 0;
}