// find the max and min difference sum in a given array
#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define ff first
#define ss second
#define pii pair<int,int>
#define vii vector<pii>
int main(){
	int n;cin>>n;
	vi a(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a.begin(),a.end());
	long long max=0,min=0;
	for(int i=0;i<n/2;i++){
		max+=(a[i+n/2]-a[i]);
		min+=(a[i*2+1]-a[i*2]);
	}
	cout<<max<<" "<<min<<endl;
	return 0;
}
