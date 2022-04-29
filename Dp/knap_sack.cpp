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


int main(){
	int n;cin>>n;
	int ans=0;
	while(n>0){
		int c=n%10;
		ans=ans*10+c;
		n=n/10;
	}
	cout<<ans;
	return 0;
}