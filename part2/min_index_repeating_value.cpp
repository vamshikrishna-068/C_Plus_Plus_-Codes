#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	int a[n];
	// cout<<"Busi"<<endl;
	// int b[n]
	for(int i=0;i<n;i++){
		cin>>a[i];
	// }
	const int N=1e6+2;
	int idx[N];
	for(int i=0;i<N;i++){
		idx[i]=-1;
	}
	int min1=INT_MAX;
	for(int i=0;i<n;i++)
	{
		int x=a[i];
		if(idx[x]==-1)
			idx[x]=i;
		else
		{
			min1=min(idx[x],min1);
		}
	}
	if(min1==INT_MAX)
		cout<<"-1"<<endl;
	else
		cout<<min1+1<<endl;

	return 0;}
}