#include <bits/stdc++.h>
using namespace std;
int main(){
	string s;
	cin>>s;
	stack<char> st;
	int k;
	bool ans=false;
	for(int i=0;i<s.size();i++){
		if(s[i]=='+' || s[i]=='-' || s[i]=='/' || s[i]=='*'){
			st.push(s[i]);
		}
		else if(s[i]=='('){
			st.push(s[i]);
		}
		else if(s[i]==')'){
			if(st.top()=='(')
				ans=true;
			while(st.top()=='+' || st.top()=='-' || st.top()=='/' || st.top()=='*')	
		{
			st.pop();
		}
		st.pop();

		}
		
	}
	if(ans){
		cout<<"Redundant"<<endl;
	}
	else
		cout<<"Not Redundant"<<endl;

	return 0;
}