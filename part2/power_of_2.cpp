#include <bits/stdc++.h>
using namespace std;
bool ispower2(int n){
	return n&&(!(n&n-1)); // to overcome n==0 case
}
int noofones(int n){
	int count=0;
	while(n){
	n=n&(n-1); //n=6==110,n-1=5==101 n&n-1=100; n=4==100 & n-1==011 n&n-1=000 
	count++; // n-1 has bits as n but flips when 1 encounters from right including it
	}
	return count;
}
int main(){
	int n;
	cin>>n;
	cout<<ispower2(n)<<endl;
	cout<<"No of ones "<<noofones(n)<<endl;
	// cout<<(n&&1)<<endl;
	return 0;
}