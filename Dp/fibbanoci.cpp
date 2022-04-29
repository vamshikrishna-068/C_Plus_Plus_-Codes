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
// Memorization(Look up table)
int DP[N]; // lookup table
int fib(int n){
	if(n==1 || n==0){
		return 0;
	}
	if(n==2){
		return 1;
	}
	if(DP[n]!=-1){
		return DP[n];
	}
	DP[n]=fib(n-1)+fib(n-2);
	return DP[n];
}
// int main(){
// 	int n;
// 	cin>>n;
// 	for(int i=0;i<N;i++){
// 		dp[i]=-1;
// 	}
// 	cout<<fib(n)<<endl;
// 	return 0;
// }
// Tabulation
int main(){
	int n;cin>>n;
	vi dp(n+1);
	dp[0]=0;
	dp[1]=0;
	dp[2]=1;
	for(int i=3;i<=n;i++){
		dp[i]=dp[i-1]+dp[i-2];
	}
	cout<<dp[n]<<endl;
	return 0;
}