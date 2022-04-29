#include <bits/stdc++.h>
using namespace std;
int main(){
	int a[3][4]={{2,4,1,2},{8,4,3,6},{1,7,9,5}};
	int b[4][3]={{1,2,3},{4,5,6},{7,8,9},{4,5,6}};
	int c[3][3]={0};
	int n1=3,n2=4,n3=3;
	for(int i=0;i<n1;i++){
		for(int j=0;j<n3;j++){
			for(int k=0;k<n2;k++){
				c[i][j]+=a[i][k]*b[k][j];
			}
		}
	}
	for(int i=0;i<n1;i++)
		{for(int j=0;j<n3;j++)
			cout<<c[i][j]<<" ";
		cout<<endl;
	}

	return 0;
}