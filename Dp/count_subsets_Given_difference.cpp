#include<bits/stdc++.h>
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
template <typename T> istream& operator>>(istream& in, vector<T>& a) {  for (T& x : a) in >> x;     return in; }
int perfect_sum(vi &a, int n, int sum){
	vector<vector<int>> dp(n+1,vector<int> (sum+1));
	for(int i=0;i<=n;i++){
		for(int j=0;j<=sum;j++){
			if(i==0) dp[i][j]=0;
			if(j==0) dp[i][j]=1;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=sum;j++){
			if(a[i-1]<=j){
				dp[i][j]=(dp[i-1][j-a[i-1]]+dp[i-1][j])%MOD;
			}
			else dp[i][j]=dp[i-1][j];
		}
	}
	return dp[n][sum];
}
int main(){
	int  n;
	cin>>n;
	vi a(n);
	cin>>a;
	int diff;cin>>diff;
	int sum=0;
	for(int i=0;i<n;i++) sum+=a[i];
	if((sum+diff)%2!=0) cout<<"0";
	else cout<<perfect_sum(a,n,(sum+diff)/2);
	return 0;
}