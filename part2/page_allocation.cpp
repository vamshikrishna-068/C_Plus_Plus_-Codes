#include <bits/stdc++.h>
using namespace std;
bool ispossible(int arr[], int n ,int m, int mid){
	int studentsrequires=1,sum=0;
	for(int i=0;i<n;i++){
		if(arr[i]>mid){
			return false;
		}
		if(sum+arr[i]>mid){
			studentsrequires++;
			sum=arr[i];

			if(studentsrequires>m){
				return false;
			}
		}
		else{
			sum+=arr[i];
		}
	}
	return true;
}
int minallocate(int arr[], int n,int m){
	int sum=0;
	if(m>n){
		return -1;
	}
	for(int i=0;i<n;i++){
		sum+=arr[i];
	}
	int start=0,end=sum,ans=INT_MAX;
	while(start<=end){
		int mid=(start+end)/2;
		if(ispossible(arr,n,m,mid)){
			ans=min(ans,mid);
			end=mid-1;
		}
		else{
			start=mid+1;
		}
	}
	return ans;
}
 int main(){
 	int arr[]={12,34,67,90};
 	int n=4,m=2;
 	cout<<"The minimum no. of pages "<<minallocate(arr,n,m)<<endl;

 	return 0;
 }