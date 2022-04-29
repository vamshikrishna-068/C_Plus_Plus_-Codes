#include<bits/stdc++.h>
using namespace std;
// min_index_repeating_value
int main(){
	int n;
	cin>>n;
	int a[n];
	// int b[n]
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	const int N=1e6+2;
	int idx[N]={-1};
	int min1=INT_MAX;
	for(int i=0;i<n;i++)
	{
		int x=a[i];
		if(idx[x]==-1)
			idx[x]=i;
		else
		{
			min1=min(i,min1);
		}
	}
	cout<<min1<<endl;

	return 0;
}