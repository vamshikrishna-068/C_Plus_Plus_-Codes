#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,m;
	cin>>n>>m;
	int a[n][m];
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++)
			cin>>a[i][j];
	}
	// Spiral_Order
	int row_start=0,row_end=n-1;
	int column_start=0,column_end=m-1;
	while(row_start<=row_end && column_start<=column_end){
		for(int j=column_start;j<=column_end;j++)
			{ cout<<a[row_start][j]<<" ";	
	}
	row_start+=1;
	// cout<<endl;
	for(int j=row_start;j<=row_end;j++){
		cout<<a[j][column_end]<<" ";
	}
	column_end-=1;
	// cout<<endl;
	for(int j=column_end;j>=column_start;j--){
		cout<<a[row_end][j]<<" ";
	}
	row_end-=1;
	// cout<<endl;
	for(int j=row_end;j>=row_start;j--){
		cout<<a[j][column_start]<<" ";
	}
	column_start+=1;
	// cout<<endl; 
}
	return 0;
}