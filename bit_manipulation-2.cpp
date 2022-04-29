#include <bits/stdc++.h>
using namespace std;
// Works except one no. is unique and every other is repeated twice
int unique_number(int arr[],int n){
 int xorsum=0;
 for(int i=0;i<n;i++)
 	xorsum^=arr[i];
 return xorsum;
}
int setbits(int n,int pos){
	return ((n&(1<<pos))!=0);
}
// two unique numbers and every other is repeated twice
 int two_unique_number(int arr[],int n){
 	int xorsum=0;
 	for(int i=0;i<n;i++){
 		xorsum^=arr[i];
 	}
 	int tempxor=xorsum;
 	int setbit=0;
 	int pos=0;
 	while(setbit!=1){
 		setbit=xorsum&1;
 		xorsum=xorsum>>1;
 		pos++;
 	}
 	int newxor=0;
 	for(int i=0;i<n;i++){
 		if(setbits(arr[i],pos-1)){
 			newxor=newxor^arr[i];
 		}

 	}
  		cout<<newxor<<endl;
 		cout<<(tempxor^newxor)<<endl;
 }
 int bit_add(int n,int pos){
 	return (n|(1<<pos));
 }
int unique_in_thrice(int a[],int n){
	int result=0;
	for(int i=0;i<64;i++){
		int sum=0;
		for(int j=0;j<n;j++){
			if(setbits(a[j],i))
				sum+=1;
		}
		if(sum%3!=0){
			result=bit_add(result,i);
		}
	}
	return result;
}
int main(){
	int a[6]={2,4,3,4,2,5};
	// cout<<unique_number(a,6)<<endl;
	// two_unique_number(a,6);
	int b[]={1,2,3,5,3,2,1,1,2,3};
	cout<<unique_in_thrice(b,10)<<endl;


	return 0;
}