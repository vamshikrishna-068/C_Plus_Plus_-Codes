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



//  Binary lifting reduces time complexity from O(n) to O(logn);


int up[200001][20];
vector<int> tree[200001];
void binary_lifting(int src, int par){
	up[src][0]=par;
	for(int i=1;i<20;i++){
		if(up[src][i-1]!=-1){
			up[src][i]=up[up[src][i-1]][i-1];
		}
		else up[src][i]=-1;
	}
	for(int child: tree[src]){
		if(child!=par){
			binary_lifting(child,src);
		}
	}
}
int ans_query(int node, int jump_req){
	if(node==-1 || jump_req==0) return node;
	for(int i=19;i>=0;i--){
		if(jump_req>=(1<<i)){
			return ans_query(up[node][i],jump_req-(1<<i));
		}
	}
}
int main(){
	ll n,q;
	cin>>n>>q;
	// vector<int> tree[n+1];
	for(int i=2;i<=n;i++){
		ll x;
		cin>>x;
		tree[x].pb(i);
		tree[i].pb(x);
	}
	binary_lifting(1,-1);
	while(q--){
		int node,jump_req;cin>>node>>jump_req;
		cout<<ans_query(node,jump_req);
	}
	return 0;
}