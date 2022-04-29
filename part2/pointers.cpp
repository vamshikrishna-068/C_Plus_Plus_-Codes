#include <bits/stdc++.h>
using namespace std;
int main(){
	int arr[]={10,20,30,40};
	// cout<<*arr<<endl;
	// arr stores the adress of zeroth element
	int *ptr=arr;
	for(int i=0;i<4;i++){
		cout<<*ptr<<endl;
		ptr++;
	}
	for(int i=0;i<4;i++){
		cout<<*(arr+i)<<endl;
		 // indexing pointer so not using 4*i
	}
	return 0;
}