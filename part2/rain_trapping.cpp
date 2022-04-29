#include <bits/stdc++.h>
using namespace std;
int main(){
	vector<int> a={0,1,0,2,1,0,1,3,2,1,2,1};
	stack<int> s;
	int n=a.size(),ans=0;
	// cout<<n<<endl;
	for(int i=0;i<n;i++){
		while(!s.empty() && a[s.top()]<a[i]){
			int cur=s.top();
			s.pop();
			if(s.empty()){
				break;
			}
			int diff=i-s.top()-1;
			ans+=(min(a[s.top()],a[i])-a[cur])*diff;
		}
		s.push(i);
	}
	cout<<ans<<endl;
	return 0;
}