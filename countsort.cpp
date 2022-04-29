#include <bits/stdc++.h>
using namespace std;
void countsort(int arr[],int n){
	int k=arr[0];
	for(int i=1;i<n;i++){
		k=max(k,arr[i]);
	}
	int count[k];
	for(int i=0;i<=k;i++){
		count[i]=0;
	}
	for(int i=0;i<n;i++){
		count[arr[i]]++;
	}
	for(int i=1;i<=k;i++)
		count[i]=count[i-1]+count[i];
	int output[n];
	for(int i=n-1;i>=0;i--){
		output[--count[arr[i]]]=arr[i];
	}
	for(int i=0;i<n;i++){
		arr[i]=output[i];
	}
}
int main(){
	int a[]={5,6,3,2,1};
	countsort(a,5);
	for(int i=0;i<5;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;

	return 0;
}