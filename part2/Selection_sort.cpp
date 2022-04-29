#include<bits/stdc++.h>
using namespace std;
// normal method :(
// int main(){
// 	int n;
// 	cin>>n;
// 	int arr[n];
// 	for(int i=0;i<n;i++)
// 		cin>>arr[i];
// 	int min;
// 	int k;
// 	for(int i=0;i<n-1;i++){
// 		min=arr[i];
// 		for(int j=i;j<n;j++){
// 			if(arr[j]<=min)
// 				{min=arr[j];
// 				k=j;
// }
// 		}
// 		swap(arr[k],arr[i]);
// 	}
// 	for(int i=0;i<n;i++)
// 		cout<<arr[i]<<" ";
// 	return 0;
// }
// Better method :)
int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];	
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(arr[i]>arr[j]){
				int temp=arr[j];
				arr[j]=arr[i];
				arr[i]=temp;
			}
		}
	}
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
	cout<<endl;


	return 0;
}