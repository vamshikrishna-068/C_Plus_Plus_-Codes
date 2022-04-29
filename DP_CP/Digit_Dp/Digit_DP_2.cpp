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
// no. of ways such that odd and even appear one by one and starting with odd
ll dp[20][2][2][2];
ll solve(string &num , int n, bool even,bool leading, bool tight){
	if(n==0) return 1;
	if(dp[n][even][leading][tight]!=-1) return dp[n][even][leading][tight];
	if(even){
		vector<int> digits={0,2,4,6,8};
		int up=(tight)?(num[num.size()-n]-'0'):9;
		ll ans=0;
		for(auto dig: digits){
			if(dig<=up) ans+=solve(num,n-1,0,0,(tight&(dig==up)));
		}
		return dp[n][even][leading][tight]=ans;
	}
	else{
		vector<int> digits={1,3,5,7,9};
		int up=(tight)?(num[num.size()-n]-'0'):9;
		ll ans=0;
		if(leading==1){
			ans+=solve(num,n-1,0,1,0);
		}
		for(int dig: digits){
			if(dig<=up) ans+=solve(num,n-1,1,0,(tight&(up==dig)));
		}
		return dp[n][even][leading][tight]=ans;
	}
}
int main(){
	int t;cin>>t;
	while(t--){
	ll L,R;cin>>L>>R;
	L--;
	string l,r;
	l=to_string(L);
	r=to_string(R);
	memset(dp,-1,sizeof dp);
	ll fr=solve(r,r.size(),0,1,1);
	memset(dp,-1,sizeof dp);
	ll fl=solve(l,l.size(),0,1,1);
	cout<<fr-fl<<endl;
	}
	return 0;
}