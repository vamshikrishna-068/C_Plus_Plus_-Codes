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
// total sum of digits which are in the range of L and R
ll dp[20][10][2][2];
ll solve(string R, ll n,int x, bool leading_zeros, bool tight){
	if(n==0) return 1;
	if(x!=-1 && dp[n][x][leading_zeros][tight]!=-1) return dp[n][x][leading_zeros][tight];
	int up=(tight)?R[R.size()-n]-'0':9;
	ll ans=0;
	for(int dig=0;dig<=up;dig++){
		if(dig==x && leading_zeros==0){
			continue;
		}
		ans+=solve(R,n-1,dig,leading_zeros & (dig==0) , tight&(dig==up));
	}
	return dp[n][x][leading_zeros][tight]=ans;
}	
int main(){
	ll l,r;cin>>l>>r;
	// if(l!=0) l--;
	string L=to_string(l-1);
	string R=to_string(r);
	memset(dp,-1,sizeof dp);
	ll fr=solve(R,R.size(),-1,1,1);
	memset(dp,-1,sizeof dp);
	ll fl=solve(L,L.size(),-1,1,1);
	cout<<fr-fl<<endl;
	return 0;
}