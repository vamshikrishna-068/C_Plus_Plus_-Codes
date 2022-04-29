#include <bits/stdc++.h>
using namespace std;
bool pairsum(int a[],int n,int k){
 int i=0,j=n-1;
 while(i<j){
 	if(a[i]+a[j]==k){
 		cout<<i<<" "<<j<<endl;
 		return true;
 	}
 	if(a[i]+a[j]<k)
 		i+=1;
 	else
 		j-=1;
 }
 return false;

}
int main(){
	int a[8]={2,4,11,7,14,20,21,16};
	sort(a,a+8);
	for(int i=0;i<8;i++)
		cout<<a[i]<<" ";
	cout<<endl;
	int k=18;

	cout<<pairsum(a,8,k)<<endl;


	return 0;
}