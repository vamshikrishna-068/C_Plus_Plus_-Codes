#include <bits/stdc++.h>
using namespace std;
int main(){
	// string s;
	// getline(cin,s);
	// cin>>s;
	string s1="fam";
	string s2="ily";
	s1.append(s2);
	cout<<s1<<endl;
	s1="fam";
	s2="ily";

	cout<<s1+s2<<endl;
	string s=s1+s2;
	cout<<s<<endl;
	s.clear();
	cout<<"after clearing"<<s<<endl;
	// comparing strings
	s1="abc";
	s2="xyz";
	cout<<"comparing s2 with s1 "<<s2.compare(s1)<<endl;
	cout<<"comparing s1 with s2 "<<s1.compare(s1)<<endl;
	// s1.clear();
	if(s1.empty())
		cout<<"empty"<<endl;
	else
		cout<<"Not empty"<<endl;
	// erasing the characters
	string a="busivamshi";
	a.erase(2,2);
	cout<<a<<endl;
	// find()
	cout<<"find()"<<endl;
	s1="busivamshi";
	cout<<s1.find("us")<<endl;
	// inserting
	cout<<"Inserting a string"<<endl;
	s1="busikrishna";
	s1.insert(4,"vamshi");
	cout<<s1<<endl;
	// size
	cout<<s1.size()<<endl;

	//SUBSTRINGS
	cout<<"SUB STRINGS"<<endl;
	s1="busivamshikrishna";
	s=s1.substr(4,6);	
	cout<<s<<endl;

	// numeric string to integer
	cout<<"numeric strings"<<endl;
	s1="981";
	int x=stoi(s1);
	cout<<x+1<<endl;
	// ineteger to string
	int y=123;
	cout<<"int to string"<<endl;
	cout<<to_string(y)+"4"<<endl;

	// sorting
	cout<<"sorting"<<endl;
	s1="busivamshikrishna";
	sort(s1.begin(),s1.end());
	cout<<s1<<endl;
	return 0;
}