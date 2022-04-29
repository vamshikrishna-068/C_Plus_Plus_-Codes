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
/*
CodeChef :- Little Elephant and T-Shirts
Little Elephant and his friends are going to a party. Each person has his own 
collection of T-Shirts. There are 100 different kind of T-Shirts. Each T-Shirt 
has a unique id between 1 and 100. No person has two T-Shirts of the same ID.
They want to know how many arrangements are there in which no two persons wear 
same T-Shirt. One arrangement is considered different from another arrangement 
if there is at least one person wearing a different kind of T-Shirt in another
arrangement

*/
/*
we are approaching the in the reverse manner it means that instead of using mask
for tshirts we are using mask for people since tshirts are 100 which means (1<<100)
is huge 
*/
int dp[101][1025];
int solve(int shirt, int mask, int n, vector<vector<int>> &tshirts){
	if(mask==((1<<n)-1)) return 1;
	if(shirt> 100) return 0;
	if(dp[shirt][mask]!=-1) return dp[shirt][mask];
	ll ans=0;
	for(int i=1;i<=n;i++){
		if(mask&(1<<(i-1))) continue;
		if(tshirts[i][shirt]){
			int temp_mask=(mask|(1<<(i-1)));
			ans=(ans+solve(shirt+1,temp_mask,n,tshirts))%mod;
		}
	}
	ans=(ans+solve(shirt+1,mask,n,tshirts))%mod;
	return dp[shirt][mask]=ans%mod;
}
int main(){
	int n;cin>>n;
	vector<vector<int>> tshirts(n+1,vector<int>(101,0));
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++) {
			int x;cin>>x;
			tshirts[i+1][x]=1;
		}
	}
	memset(dp,-1,sizeof dp);
	cout<<solve(1,0,n,tshirts)<<endl;

	return 0;
}