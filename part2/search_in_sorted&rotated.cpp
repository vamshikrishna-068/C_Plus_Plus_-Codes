#include <bits/stdc++.h>
using namespace std;

int searchInRotatedArray(int arr[],int key, int left, int right){
	if(left>right)
		return -1;
	int mid=(left+right)/2;
	if(arr[mid]==key){
		return mid;
	}
	if(arr[left]<=arr[mid]){
		if(key>=arr[left] && key<=arr[mid]){
			return searchInRotatedArray(arr,key,left,mid-1);
		}
		return searchInRotatedArray(arr,key,mid+1,right);
	}
	if(key>=arr[mid] && key<=arr[right]){
		return searchInRotatedArray(arr,key,mid+1,right);
	}
	return searchInRotatedArray(arr,key,left,mid-1);
}
int main(){
	int a[]={6,7,8,9,10,1,2,5};
	int n=8;
	int key=1;
	int i=searchInRotatedArray(a,key,0,n-1);
	if(i==-1){
		cout<<"No such key exists"<<endl;
	}
	else{
		cout<<"Eixsts at : "<<i<<endl;
	}
	return 0;
}