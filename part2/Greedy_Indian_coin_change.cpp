// Find the minimum no. of coins to make a sum of x
#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define ff first
#define ss second
int main(){
	int n;
	cin>>n;
	vi a(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int x;
	cin>>x;
	sort(a.begin(),a.end(),greater<int>());
	int ans=0;
	for(int i=0;i<n;i++){
		ans+=x/a[i];
		x-=x/a[i]*a[i];

	}
	cout<<ans<<endl;
	return 0;
}