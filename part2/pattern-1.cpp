#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{	if(i==0 || i==n-1){
		for(int j=0;j<m;j++)
			cout<<"*"<<" ";
	}
	else{
		for(int j=0;j<m;j++){
			{if(j==0 || j==m-1)
				cout<<"* ";
			else
				cout<<"  ";}
			}
		}
		cout<<endl;	
	}


	return 0;
}