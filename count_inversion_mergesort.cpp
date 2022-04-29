// not getting correct output
// for n=8 & a={3 5 6 9 1 2 7 8} ans should be 10,but getting 4:( 

#include <bits/stdc++.h>
using namespace std;
long long merge(int arr[],int l,int mid,int r){
	long long inv=0;
	int n1=mid-l+1;
	int n2=r-mid;
	int a[n1];
	int b[n2];
	for(int i=0;i<n1;i++){
		a[i]=arr[l+i];
	}
	for(int i=0;i<n2;i++){
		b[i]=arr[mid+i+1];
	}
	int i=0,j=0,k=l;
	while(i<n1 && j<n2){
		if(a[i]<=b[j]){
			arr[k]=a[i];
			i++;
			k++;
		}
		else{
			arr[k]=b[j];
			k++;
			j++;
			inv+=n1-i;
		}
		while(i<n1){
			arr[k]=a[i];
			i++;
			k++;
		}
		while(j<n2){
			arr[k]=b[j];
			j++;
			k++;
		}
	}
	return inv;
}
long long mergesort(int a[],int l , int r){
	long long inv=0;
	if(l<r){
		int mid=(l+r)/2;
		inv+=mergesort(a,l,mid);
		inv+=mergesort(a,mid+1,r);
		inv+=merge(a,l,mid,r);
	}
	return inv;
}
int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	cout<<mergesort(a,0,n-1)<<endl;
	return 0;
}