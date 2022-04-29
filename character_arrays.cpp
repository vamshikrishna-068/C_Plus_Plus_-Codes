#include <bits/stdc++.h>
using namespace std;
int main(){
	// Method-1
	// char a[100]="apple";
	// int i=0;
	// while(a[i]!='\0'){
	// 	cout<<a[i]<<endl;
	// 	i++;
	// }
	//Method-2
	// char a[100];
	// cin>>a;
	// cout<<a<<endl;
	//method 3
	// To take sentence as inpu
	int n;
	cin>>n;
	cin.ignore();
	char a[n+1];
	cin.getline(a,n);
	cin.ignore();
	int i=0;
	int currlen=0;
	int maxlen=0;
	while(1){
		if(a[i]=='\0')
			break;
		if(a[i]==' ' || a[i]=='\0'){
			maxlen=max(maxlen,currlen);
			currlen=0;
		}
		else
			currlen+=1;
		i++;
	}
	cout<<maxlen<<endl;
	return 0;
}