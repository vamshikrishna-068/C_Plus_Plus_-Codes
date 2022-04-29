#include <bits/stdc++.h>
using namespace std;
int firstoccurence(int a[],int n,int i,int key){
	if(i==n)
		return -1;
	
	if(a[i]==key)
		return i;
	return firstoccurence(a,n,i+1,key);

}
int lastoccurence(int a[],int n,int i,int key){
	if(i==n)
	return -1;
	int restArray=lastoccurence(a,n,i+1,key);
	if(restArray!=-1)
		return restArray;
	if(a[i]==key)
		return i;
	else
		return -1;
}
int main(){
	int arr[]={4,2,1,2,5,2,7};
	// cout<<firstoccurence(arr,7,0,2);
	cout<<lastoccurence(arr,7,0,2)<<endl;;

	return 0;
}