#include <bits/stdc++.h>
using namespace std;
int kadane(int arr[],int n)
{
	int currentsum=0;
	int maxsum=INT_MIN;
	for(int i=0;i<n;i++)
	{
		currentsum+=arr[i];
		if(currentsum<0)
			currentsum=0;
		maxsum=max(maxsum,currentsum);
	}
	return maxsum;
}
int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	int sum=0;
	for(int i=0;i<n;i++){
		sum+=a[i];
	}
	int wrapsum, nonwrapsum;
	nonwrapsum=kadane(a,n);
	for(int i=0; i<n;i++){
		a[i]*=-1;
	}
	wrapsum=sum+kadane(a,n);
	
	cout<<max(wrapsum,nonwrapsum)<<endl;
	return 0;
}