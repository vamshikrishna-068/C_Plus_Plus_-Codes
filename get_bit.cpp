#include <bits/stdc++.h>
using namespace std;
int getbit(int n,int pos){
	return((n&(1<<pos))!=0);
}
int setbit(int n,int pos){
	return(n|(1<<pos));
}
int clearbit(int n,int pos){
	return(n&(~(1<<pos)));
} 
int updatebit(int n,int pos , int value){
	int mask=~(1<<pos);
	n=n&mask;
	return (n| (value<<pos));
}
int main(){

	cout<<getbit(6,1)<<endl;
	cout<<setbit(5,3)<<endl;
	cout<<clearbit(5,2)<<endl;
	cout<<updatebit(5,1,1)<<endl;
	return 0;
}