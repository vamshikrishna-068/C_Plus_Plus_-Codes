#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> ans;
void permutate(vector<int> &a, int idx){
	if(idx==a.size())
		{ans.push_back(a);
			return;
		}
	for(int i=idx;i<a.size();i++){

		swap(a[i],a[idx]);
		permutate(a,idx+1);
		swap(a[i],a[idx]);
	}

}
void permutate_unique(vector<int> &a,int idx){
	if(idx==a.size())
		{ans.push_back(a);
			return;}
	for(int i=idx;i<a.size();i++){
		if(i!=idx && a[i]==a[idx]){
			continue;
		}
		swap(a[i],a[idx]);
		permutate_unique(a,idx+1);
	}
	}
int main(){
	int n;cin>>n;
	vector<int> a(n);
	for(auto &i: a)
		cin>>i;
	permutate(a,0);
	// permutate_unique(a,0);
	for(auto v: ans){
		for(auto i: v){
			cout<<i<<" ";
		}
		cout<<endl;
	}
	return 0;
}
// Method -2 STL trick for permutations
// int main(){
// 	int n;cin>>n;
// 	vector<int> a(n);

// 	for(auto &i:a){
// 		cin>>i;
// 	}
// 	sort(a.begin(),a.end());
// 	do{
// 		ans.push_back(a);
// 	}while(next_permutation(a.begin(),a.end()));
// 	for(auto v: ans){
// 		for(auto i: v){
// 			cout<<i<<" ";
// 		}
// 		cout<<endl;
// 	}

// 	return 0;
// }