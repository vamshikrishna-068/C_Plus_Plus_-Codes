#include <bits/stdc++.h>
using namespace std;
#include<math.h>
int prefixevaluation(string s){
	stack<int> st;
	for(int i=s.length()-1;i>=0;i--){
		if(s[i]>='0' && s[i]<='9'){
			st.push(s[i]-'0');
		}
		else{
			int op1=st.top();
			st.pop();
			int op2=st.top();
			st.pop();
			switch(s[i])
			{
				case '+':
					st.push(op1+op2);
					break;
				case '-':
					st.push(op1-op2);
					break;
				case '*':
					st.push(op1*op2);
					break;
				case '/':
					st.push(op1/op2);
					break;
				case '^':
					st.push(pow(op1,op2));
					break;
				default:
					break;
			}
		}
	}
	return st.top();
}
int postfixevaluation(string s){
	stack<int> st;
	for(int i=0;i<s.length();i++){
		if(s[i]>='0' && s[i]<='9'){
			st.push(s[i]-'0');
		}
		else{
			int op2=st.top();
			st.pop();
			int op1=st.top();
			st.pop();
			switch(s[i])
			{
				case '+':
					st.push(op1+op2);
					break;
				case '-':
					st.push(op1-op2);
					break;
				case '*':
					st.push(op1*op2);
					break;
				case '/':
					st.push(op1/op2);
					break;
				case '^':
					st.push(pow(op1,op2));
					break;
				default:
					break;
			}
		}
	}
	return st.top();
}
int main(){
	string s="-+7*45+20";
	// int a=prefixevaluation(s);
	// cout<<a<<endl;
	string a="36+";
	cout<<postfixevaluation("46+2/5*7+")<<endl;
	return 0;
}