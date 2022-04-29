#include <bits/stdc++.h>
using namespace std;
int  partition(int a[], int l, int r){
	int pivot=a[r];
	int i=l-1;
	for(int j=l;j<r;j++){
		if(a[j]<pivot){
			i++;
			swap(a[i],a[j]);
		}
	}
	swap(a[i+1],a[r]);
	return i+1;

}
void quicksort(int a[],int l,int r){
	if(l<r){
		int pi=partition(a,l,r);
		quicksort(a,l,pi-1);
		quicksort(a,pi+1,r);
	}
}
int main(){
	int a[]={5,6,3,2,1};
	quicksort(a,0,4);
	for(int i=0;i<5;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;

	return 0;
}