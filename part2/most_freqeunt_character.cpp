#include <bits/stdc++.h>
using namespace std;
int main(){
	string s;
	cin>>s;
	int  freq[26]={0};
	for(int i=0;i<s.size();i++){
		freq[s[i]-'a']++;
	}
	int max1=0;
	char ans='a';
	for(int i=0;i<26;i++)
		{ 
			if(freq[i]>max1){
				max1=freq[i];
				ans+=i;
			}
		}
	cout<<ans<<" "<<max1<<endl;
	return 0;
}