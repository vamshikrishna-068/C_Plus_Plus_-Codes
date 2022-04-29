#include <bits/stdc++.h>
using namespace std;
void subseq(string s, string ans){
	if(s.length()==0){
		cout<<ans<<endl;
		return;
	}
	char ch=s[0];
	string ros=s.substr(1);
	subseq(ros,ans);
	subseq(ros,ans+ch);
}
void subseqwithASCII(string s,string ans){
	if(s.length()==0){ 
		cout<<ans<<endl; 
		return;
	}
	char ch=s[0];
	int code=ch;
	string ros=s.substr(1);
	subseqwithASCII(s,ans);
	subseqwithASCII(s,ans+ch);
	subseqwithASCII(s,ans+to_string(code));
}
int main(){
	// subseq("abc","");
	subseqwithASCII("AB","");
	return 0;
}