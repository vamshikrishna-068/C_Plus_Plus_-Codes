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

string print_shortest_common_sequence(string s1, string s2, int n, int m){
	vector<vector<int>> dp(n+1, vector<int> (m+1));
	for(int i=0;i<=n;i++) for(int j=0;j<=m;j++) if(i==0 || j==0 ) dp[i][j]=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(s1[i-1]==s2[j-1]) dp[i][j]=dp[i-1][j-1]+1;
			else dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
		}
	}
	int i=n,j=m;
	string ans="";
	while(i>0 && j>0){
		if(s1[i-1]==s2[j-1]){ ans=s1[i-1]+ans; i--;j--;}
		else if(dp[i][j-1]>dp[i-1][j]){
			ans=s2[j-1]+ans;
			j--;
		}
		else{
			ans=s1[i-1]+ans;
			i--;
		}
	}
	while(i>0){
		ans=s1[i-1]+ans;
		i--;
	}
	while(j>0){
		ans=s2[j-1]+ans;
		j--;
	}
	return ans;
}

int main(){
	string s1,s2;cin>>s1>>s2;
	int n=s1.length();
	int m=s2.length();
	cout<<print_shortest_common_sequence(s1,s2,n,m);
	return 0;
}