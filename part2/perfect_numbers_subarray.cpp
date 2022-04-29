// find the perfect numbers in Subarrays of size k in an array
// perfect numbers: sum of proper divisors except itself is equal to the number
// Eg :-  proper divisors of 6 are 1,2,3 and 1+2+3=6 so its a perfect number  
#include <bits/stdc++.h>
using namespace std;
// ******* Code for Perfect Numbers**********
bool isNumberPerfect(int n){
	int sum=1;
	for(int i=2;i<sqrt(n);i++){
		if(n%i==0){
			if(i==n/i){
				sum+=i;
			}
			else{
				sum+=i+n/i;
			}
		}
	}
	if(sum==n && n!=1){
		return true;
	}
	else{
		return false;
	}
}
int maxsum(int arr[], int n , int k){
	if(n<k){
		cout<<"Invalid values"<<endl;
		return -1;
	}
	int res=0;
	int sum=0;
	for(int i=0;i<k;i++){
		sum+=arr[i];
	}
	res=sum;
	for(int i=k;i<n;i++){
		sum=sum-arr[i-k]+arr[i];
		res=max(res,sum);
	}
	return res;
}
int maxNumberOfPerfects(int arr[], int n, int k){
	for(int i=0;i<n;i++){
		if(isNumberPerfect(arr[i])){
			arr[i]=1;
		}
		else{
			arr[i]=0;
		}
	}
	return maxsum(arr,n,k);
}
int main(){
	int arr[]={28,2,3,6,496,99,8128,24};
	int n=8;
	int k=4;
	cout<<maxNumberOfPerfects(arr,n,k)<<endl;
	return 0;
}