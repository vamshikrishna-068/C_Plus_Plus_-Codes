#include <bits/stdc++.h>
using namespace std;
void primeSeive(int n){
	int prime[100]={0};
	// choose n<100 since we have prime[100]
	for(int i=2;i<=n;i++){
		if(prime[i]==0){
			for(int j=i*i;j<=n;j+=i){
				prime[j]=1;
			}
		}
	}
	for(int i=2;i<=n;i++ ){
		if(prime[i]==0)
			cout<<i<<" ";
	}
	cout<<endl;
}
void primefactor(int n){
	int spf[100]={0};
	for(int i=2;i<=n;i++)
		spf[i]=i;
	for(int i=2;i<=n;i++){
		if(spf[i]==i){
			for(int j=i*i;j<=n;j+=i){
				if(spf[j]==j){
					spf[j]=i;
				}
			}
		}
	}
	while(n!=1){
		cout<<spf[n]<<" ";
		n=n/spf[n];
	}
}
int main(){
	int n;
	cin>>n;
	// prime numbers between 1 and n
	// primeSeive(n);
	// Prime factors of n
	primefactor(n);
	return 0;
}