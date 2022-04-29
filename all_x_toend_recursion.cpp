#include <bits/stdc++.h>
using namespace std;
string allxtoend(string s){
	if(s.length()==0)
		return "";
	char ch=s[0];
	string ans=allxtoend(s.substr(1));
	if(ch=='x')
		return ans+ch;
	else return ch+ans;

}
int main(){
	cout<<allxtoend("axxbdxcefxhix")<<endl;
}