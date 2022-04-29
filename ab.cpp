#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define ff first
#define ss second
#define pii pair<int,int>
#define vii vector<pii>
const int N=1e5+2,MOD=1e9+7;
int main(){
	vector<int> a={2,5,1,3};
	sort(a.begin(),a.end());
	for(auto i=a.begin();i!=a.end();i++){
		cout<<*i<<endl;
	}
	return 0;
}