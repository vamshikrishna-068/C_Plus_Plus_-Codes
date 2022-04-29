#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,target;
	cin>>n>>target;
	vector<int> v(n);
	for(auto &i: v)
		cin>>i;
	bool found=false;
	sort(v.begin(),v.end());
	for(int i=0;i<n;i++){
		int lo=i+1;
		int hg=n-1;
		while(lo<hg){
			int current=v[i]+v[lo]+v[hg];
			if(current==target){
				found=true;
			}
		}
	}
	if(found){
		cout<<"True"<<endl;
	}
	else{
		cout<<"false"<<endl;
	}
	return 0;
}