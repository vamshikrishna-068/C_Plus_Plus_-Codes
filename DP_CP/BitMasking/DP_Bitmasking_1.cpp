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
Q:
Let there be N workers and N jobs. Any worker can be assigned to perform any 
job, incurring some cost that may vary depending on the work-job assignment. 
It is required to perform all jobs by assigning exactly one worker to each job 
and exactly one job to each agent in such a way that the total cost of the 
assignment is minimized.
*/
int dp[21][(1<<21)];
int solve(int i, int mask, vector<vector<int>> &c, int &n){
	if(i==n) return 0;
	if(dp[i][mask]!=-1) return dp[i][mask];
	int ans=INT_MAX;
	for(int j=0;j<n;j++){
		if(mask&(1<<j)){
			ans=min(ans,c[i][j]+solve(i+1,mask^(1<<j),c,n));
		}
	}
	return dp[i][mask]=ans;
}
int main(){
	int n;cin>>n;
	vector<vector<int>>c (n,vector<int>(n,0));
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>c[i][j];
		}
	}
	memset(dp, -1, sizeof dp);
	cout<<solve(0,(1<<n)-1,c,n)<<endl;
	return 0;
}