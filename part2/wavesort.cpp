#include <bits/stdc++.h>
using namespace std;
void wavesort(int a[],int n){
	for(int i=1;i<n;i+=2){
		if(a[i]>a[i-1]){
			swap(a[i],a[i-1]);
		}
		if(a[i]>a[i+1] && i<=n-2){
			swap(a[i],a[i+1]);
		}
	}
}
int main(){
	int a[]={1,3,4,7,5,6,2};
	wavesort(a,7);
	for(int i=0;i<7;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
	return 0;
}