#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define ff first
#define ss second   
#define pii pair<int,int>
#define vii vector<pii>
#define ll long long
#define vll vector<long long>
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define all(a) a.begin(),a.end()
const int N=1e6+10,mod=1e9+7;
const int inf=1e9+2;
// int mod=998244353,N=1005;
template <typename T> istream& operator>>(istream& in, vector<T>& a) {  for (T& x : a) in >> x;     return in; }
ll ceil_div(ll a, ll b) {return a % b == 0 ? a / b : a / b + 1;}
ll gcd(ll a, ll b) { if (b == 0) return a; return gcd(b, a % b);}
ll mod_add(ll a, ll b) {a = a % mod; b = b % mod; return (((a + b) % mod) + mod) % mod;}
ll mod_mul(ll a, ll b) {a = a % mod; b = b % mod; return (((a * b) % mod) + mod) % mod;}
ll expo(ll a, ll b, ll mod){ll res=1; while(b>0){ if(b&1)res=(res*a)%mod; a=(a*a)%mod; b>>=1;} return res;}
ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
vll isprime(N,1);
// sort in descending order
bool desc(ll a, ll b)
{	return a>b;
}
vll primes;
// Primes
void seive(ll n=N){
	isprime[0]=isprime[1]=0;
	for(ll i=2;i<=n;i++){
		if(isprime[i]){
			for(ll j=i*i;j<=n;j+=i){
				isprime[j]=0;
			}
		}
	}
	for(ll i=2;i<=n;i++){
		if(isprime[i]) primes.pb(i);
	}
}
bool f(pair<ll,ll> a, pair<ll,ll> b){
	return a.second>b.second;
}

ll power(ll a , ll b){
	ll ans=1;
	while(b>0){
		if(b&1) ans=ans*a;
		a=a*a;
		b>>=1;
	}
	return ans;
}
// log2 is used to find the length of a number in bits
// find the no of numbers which are in range from 0 to R whose sum of digits is equal to x; 
int dp[100][151][2];
int solve(string &num , int n, int x, bool tight){
	// if(n==0){
	// 	if(x==0) return 1;
	// 	return 0;
	// }
	if(x<0) return 0;
	if(n==1){
		if(x>=0 && x<=9) return 1;
		else return 0;
	}
	if(dp[n][x][tight]!=-1) return dp[n][x][tight];
	int ans=0;
	int up=(tight)? (num[num.size()-n]-'0'):9;
	for(int dig=0;dig<=up;dig++){
		ans+=solve(num,n-1,x-dig,(tight&(up==dig)));
	}
	return dp[n][x][tight]=ans;
}
int main(){
	memset(dp,-1,sizeof dp);
	string R="1120343423443535";
	cout<<solve(R,R.size(),15,1);
	return 0;
}