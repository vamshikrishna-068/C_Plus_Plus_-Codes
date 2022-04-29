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
int dp_max(vi &a, int n){
    vi dp(n+1,INT_MIN);
    dp[0]=0;
    // for(int j=1;j<=n;j++){
    // for(int i=1;i<=j;i++){
    //     dp[i]=max(dp[i],a[i-1]+dp[i-1]);
    // }}
    for(int i=1;i<=n;i++){

       // int max_val = INT_MIN;
        for(int j=0;j<i;j++){
            dp[i]=max(dp[i],dp[i-j-1]+a[j]); // 0 indexing :) :)
            // if(j==n-1) cout<<"busii";

        }
        // dp[i]=max_val;
    }
    return dp[n];
}

// method -2 like unbounded knapsack
int unbounded_knp(vi &a, int n){
    vector<vector<int>> dp(n+1,vector<int>(n+1));
    for(int i=0;i<=n;i++) for(int j=0;j<=n;j++) if(i==0 || j==0) dp[i][j]=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i<=j) dp[i][j]=max(a[i-1]+dp[i][j-i],dp[i-1][j]);
            else dp[i][j]=dp[i-1][j];
        }
    }// actually i represents a length array like [1,2,3,4,5,6,7,8] for 8 length :)
    return dp[n][n];
}
int main(){
	int n;cin>>n;
	vi a(n);
	cin>>a;
	// cout<<dp_max(a,n);
    cout<<unbounded_knp(a,n);
	return 0;
}