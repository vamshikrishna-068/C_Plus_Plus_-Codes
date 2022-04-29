#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int ans=2;
	int pd=a[1]-a[0];
	int c=2;
	for(int i=2;i<n;i++)
	{
		if((a[i]-a[i-1])==pd){
			c+=1;
		}
		else{

			// cout<<"ans"<<ans<<endl;
			pd=a[i]-a[i-1];
			c=2;
		}
			ans=max(ans,c);
	}

	cout<<ans<<endl;

	return 0;
}