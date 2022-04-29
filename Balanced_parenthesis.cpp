#include <bits/stdc++.h>
using namespace std;
bool isvalid(string s){
	stack<char> st;
	bool ans=true;
	for(int i=0;i<s.length();i++){
		if(s[i]=='{' || s[i]=='[' || s[i]=='('){
			st.push(s[i]);
		}
		else if(s[i]=='}' || s[i]==']' || s[i]==')'){
			if(st.empty()){
				ans=false;
				break;
			}
			if((st.top()=='(' && s[i]==')') || (st.top()=='[' && s[i]==']') || (st.top()=='{' && s[i]=='}')){
				st.pop();
			}
			else
				{
				ans= false;
				break;
				 }
		}


	}
	if(!st.empty())
		ans=false;
 return ans;

}
int main(){
	string s="()]";
	if(isvalid(s)){
		cout<<"Valid string"<<endl;
	}
	else{
		cout<<"Invalid string"<<endl;
	}
	return 0;
}