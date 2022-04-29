// forming a number which is divisible by 3 from the array with size k elements
#include <bits/stdc++.h>
using namespace std;
void NumberDivisibleBy_3_Subarray(int arr[], int n, int k){
	int sum=0;
	pair<int,int> ans;
	for(int i=0;i<k;i++){
		sum+=arr[i];
	}
	bool found=false;
	if(sum%3==0){
		ans=make_pair(0,k-1);
		found = true;
	}
	for(int j=k;j<n;j++){
		if(found){
			break;
		}
		sum=sum+arr[j]-arr[j-k];
		if(sum%3==0){
			ans=make_pair(j-k+1,j);
			found=true;
		}
	}
	if(found){
		for(int i=ans.first;i<=ans.second;i++){
			cout<<arr[i]<<" ";
		}
		cout<<endl;
	}
	else{
		cout<<"no such subarray exists"<<endl;
	}
}
int main(){
	int arr[]={84,23,45,12,56,82};
	int k=3;
	int n=6;
	NumberDivisibleBy_3_Subarray(arr,n,k);
	return 0;
}