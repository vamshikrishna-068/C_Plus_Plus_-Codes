// finding the minimum subarray which has sum>x
#include <bits/stdc++.h>
using namespace std;
int smallestSubarrayWithSum(int arr[], int n,int x){
	int sum=0, minlength=n+1, start=0,end=0;
	while(end<n){
		while(sum<=x && end<n){
			sum+=arr[end++];

		}
		while(sum>x){
			if(end-start < minlength){
				minlength=end-start;
			}
			sum-=arr[start++];
		}
	}
	return minlength;
}

int main(){
	int arr[]={1,4,45,6,10,19};
	int n=6;
	int x=51;
	int minlength=smallestSubarrayWithSum(arr,n,x);
	if(minlength==n+1){
		cout<<"No such element exists "<<endl;
	}
	else{
		cout<<"Smallest subarray with sum (>x) "<<minlength<<endl;
	}
	return 0;

}