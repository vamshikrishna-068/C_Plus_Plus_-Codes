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

int lcs(string s1, string s2, int n, int m){
	vector<vector<int>> dp(n+1, vector<int> (m+1));
	for(int i=0;i<=n;i++) 
		{
			for(int j=0;j<=m;j++) {
				if(i==0 || j==0 ) dp[i][j]=0;
			}

		}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(s1[i-1]==s2[j-1]) dp[i][j]=dp[i-1][j-1]+1;
			else dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
		}
	}
	return dp[n][m];
}

int main(){
	string s1;cin>>s1;
	string s2=s1;
	int n=s1.length();
	reverse(s1.begin(),s1.end()); 
// given a string and reverse it and find the lcs of Original and Reverse
	cout<<lcs(s1,s2,n,n);
	return 0;
}