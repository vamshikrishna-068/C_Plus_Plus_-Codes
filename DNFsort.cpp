#include <bits/stdc++.h>
using namespace std;
void dnf(int a[],int n){
	int low=0;
	int high=n-1;
	int mid=0;
	while(mid<=high){
		if(a[mid]==0){
			swap(a[low],a[mid]);
			low++;
			mid++;
		}
		else if(a[mid]==1){
			mid++;
		}
		else{
			swap(a[mid],a[high]);
			high--;
		}
	}
}
int main(){
	int a[]={0,1,2,2,1,0,1,2};
	dnf(a,8);
	for(int i=0;i<8;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
	return 0;
}