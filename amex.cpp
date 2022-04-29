#include<bits/stdc++.h>
using	namespace std;
#define lli 	long long int
vector<string> deepthegod(string a) {
	vector<string> subvalues;
	lli l = -1;
	lli n = a.length();
	for (lli i = 0; i < n; i++) {
		if (a[i] == ',') {
			subvalues.push_back(a.substr(l + 1, i-l-1));
			l = i;
		}
	}
	subvalues.push_back(a.substr(l + 1,n-l-1));
	return subvalues;

}

struct bur {
	string	busi;
	lli as;
	lli ta;
	lli tl;
	lli hof;
	lli bscore;
	lli cl;

} b;

struct application {
	string	busi;
	string roll;
	lli money;
} a;


int main() {
	lli n = 1, m;
	cin >> n;
	map<string, bur> sb;
	string s,busi;
	vector<string> substring;
	for (lli i = 0; i < n; i++) {
		cin >> s;
		substring = deepthegod(s);
		try {
			b.busi = substring[0] + substring[1];
			b.as = stoi(substring[2]);
			b.ta = stoi(substring[3]);
			b.tl = stoi(substring[4]);
			b.hof = stoi(substring[5]);
			b.bscore = stoi(substring[6]);
			b.cl = stoi(substring[7]);
			busi = substring[0] + substring[1];
		}
		catch (...) {
			continue;
		}
		sb[busi] = b;
	}
	lli sum = 0, total = 0;
	for (auto it : sb) {
		sum=sum+ 1;
		total =total + it.second.as;
	}
	lli average = total/sum;

	cin >> m;
	string roll;
	lli money;
	vector<pair<string, string>> vec;
	for (lli i = 0; i < m; i++) {
		cin >> s;
		substring = deepthegod(s);

		busi = substring[1] + substring[2];
		roll = substring[0];
		money = stoi(substring[3]);

		if (sb.count(substring[1] + substring[2])) {
			busi = substring[1] + substring[2];
			if ((sb[busi].ta > sb[busi].tl) && (sb[busi].bscore > 50) && ((float)(sb[busi].as * 1.0 / money) > 0.1) && (sb[busi].as > average)) {
				vec.push_back(make_pair(roll, "Yes"));
			}
			else if ((sb[busi].ta > sb[busi].tl) && (sb[busi].bscore > 30) && ((sb[busi].as / money) > 0.1) && (sb[busi].as > average) && (sb[busi].hof == 1)) {
				vec.push_back(make_pair(roll, "Yes"));
			}
			else {
				vec.push_back(make_pair(roll, "No"));
			}

		}
		else if (sb.count(substring[2] + substring[1])) {
			busi = substring[2] + substring[1];
			if ((sb[busi].ta > sb[busi].tl) && (sb[busi].bscore > 50) && ((sb[busi].as / money) > 0.1) && (sb[busi].as > average)) {
				vec.push_back(make_pair(roll, "Yes"));
			}
			else if ((sb[busi].ta > sb[busi].tl) && (sb[busi].bscore > 30) && ((sb[busi].as / money) > 0.1) && (sb[busi].as > average) && (sb[busi].hof == 1)) {
				vec.push_back(make_pair(roll, "Yes"));

			}
			else {
				vec.push_back(make_pair(roll, "No"));
			}

		}
		else {
			vec.push_back(make_pair(roll, "No"));
		}
	}
	sort(vec.begin(),vec.end());
	for (auto itr : vec) {
		cout << itr.first << "," << itr.second<< endl;
	}
	return 0;
}