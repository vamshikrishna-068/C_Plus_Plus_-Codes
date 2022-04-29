#include <bits/stdc++.h>
using namespace std;
int countpath(int s,int e){
	if(s==e)
		return 1;
	if(s>e)
		return 0;
	int count=0;
	for(int i=1;i<=6;i++){ //DICE 6 possible values
		count+=countpath(s+i,e);
	}
	return count;
}
int countpath_maze(int n,int i,int j){
	if(i==n-1 && j==n-1){
		return 1;
	}
	if(i>=n || j>=n)
		return 0;
	return countpath_maze(n,i+1,j)+countpath_maze(n,i,j+1);
}
int main(){
	// cout<<countpath(0,3);
	cout<<countpath_maze(3,0,0);
	return 0;
}