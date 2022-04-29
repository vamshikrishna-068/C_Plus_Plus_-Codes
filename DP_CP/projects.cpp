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

struct job{
	int start,finish,money;

};
bool cmp(job a, job b){
	return a.finish<b.finish;
}
ll find_pos(ll val, ll i, vector<job> &a){
	ll l=0,r=i-1;
	ll ans=-1;
	while(l<=r){
		ll mid=l+(r-l)/2;
		if(a[mid].finish<val){
			ans=mid;
			l=mid+1;
		}
		else{
			r=mid-1;
		}
	}
	// cout<<ans<<endl;
	return ans;
}
int main(){
	ll n;cin>>n;
	vector<job> a(n);
	for(ll i=0;i<n;i++){
		cin>>a[i].start>>a[i].finish>>a[i].money;
	}
	sort(all(a),cmp);
	vll dp(n);
	dp[0]=a[0].money;
	for(ll i=1;i<n;i++){
		ll temp=a[i].money;
		ll search=find_pos(a[i].start,i,a);
		if(search!=-1) temp+=dp[search];
		dp[i]=max(dp[i-1],temp);
	}
	cout<<dp[n-1]<<endl;
	return 0;
}