// stock span problem..
#include <bits/stdc++.h>
using namespace std;
vector<int> stock_span(vector<int> a){
	vector<int> ans;
	stack<pair<int,int>> s;
	for(auto price: a){
		int days=1;
		while(!s.empty() && s.top().first<=price){
			days+=s.top().second;
			s.pop();
		}
		s.push({price,days});
		ans.push_back(days);
	}
	return ans;
}
int main()
{
	vector<int > v={100,80,60,70,60,75,85};
	vector<int> res=stock_span(v);
	for(auto i: res){
		cout<<i<<" ";
	}
	cout<<endl;
	return 0;
}