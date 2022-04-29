#include<bits/stdc++.h>
using namespace std;
using namespace chrono;
#define ll 					long long int
#define float	 			long double
#define pb 					push_back
#define ppb 				pop_back
#define pf 					push_front
#define ppf 				pop_front
#define lb 					lower_bound
#define ub 					upper_bound
#define F 					first
#define S 					second
#define all(x)				(x).begin(), (x).end()
#define line 				cout<<"\n";
#define endl 				"\n";
#define IOS		 			ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
#define deb(x) 				cout << "DEBUG "<< #x << " " ;	 _print(x); cout << endl;
#define deb2(x, y) 			cout << "DEBUG "<< #x << " = ";  _print(x); cout << " " << #y << " = "; _print(y); cout << endl;
#else
#define deb(x);
#define deb2(x,y);
#endif

typedef vector<ll> 			vll;
typedef pair<ll, ll> 		pll;
typedef map<ll, ll> 		mll;
typedef set<ll> 			sll;
typedef priority_queue<ll> 	pqll;
typedef queue<ll> 			qll;
typedef deque<ll>       	dqll;
void _print(ll t) 			{cout << t;}
void _print(int t)			{cout << t;}
void _print(double t) 		{cout << t;}
void _print(string t) 		{cout << t;}
void _print(char t) 		{cout << t;}
void _print(float t) 		{cout << t;}
void _print(bool t) 		{cout << t;}
template <class T, class V> void _print(pair <T, V> p);
template <class T> 			void _print(vector <T> v);
template <class T> 			void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T, class V> void _print(pair <T, V> p)	{cout << "{"; _print(p.F); cout << ","; _print(p.S); cout << "}";}
template <class T> 			void _print(vector <T> v) 	{cout << "[ "; for (T i : v) {_print(i); cout << " ";} cout << "]";}
template <class T> 			void _print(deque <T> v) 	{cout << "[ "; for (T i : v) {_print(i); cout << " ";} cout << "]";}
template <class T> 			void _print(set <T> v) 		{cout << "[ "; for (T i : v) {_print(i); cout << " ";} cout << "]";}
template <class T, class V> void _print(map <T, V> v) 	{cout << "[ "; for (auto i : v) {_print(i); cout << " ";} cout << "]";}
template <typename T> istream& operator>>(istream& in, vector<T>& a) { 	for (T& x : a) in >> x; 	return in; }

const ll mod = 1e9 + 7;
const ll inf = 1e16 + 7;
const ll mxn = 1e5 + 7;

ll findParent(ll x, vll &parentArr) {
	if (x == parentArr[x]) return x;
	return parentArr[x] = findParent(parentArr[x], parentArr);
}

void merge(ll x, ll y, vll &rankArr, vll &parentArr) {

	x = findParent(x, parentArr);
	y = findParent(y, parentArr);
	if (rankArr[x] > rankArr[y]) {
		parentArr[y] = x;
	}
	else if (rankArr[y]  > rankArr[x]) {
		parentArr[x] = y;
	}
	else {
		rankArr[x]++;
		parentArr[y] = x;
	}

}

int main() {
	IOS
	auto start1 = high_resolution_clock::now();
	cout << fixed << setprecision(12);

	ll n, m;
	cin >> n >> m;
	vll rankArr(n, 0);
	vll parentArr(n, 0);
	for (int i = 0; i < n; i++) parentArr[i] = i;
// minpq
	priority_queue<pair<ll, pll>, vector<pair<ll, pll>>, greater<pair<ll, pll>>> pq;
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		pq.push({w, {u, v}});
	}
	ll cost = 0;
	while (!pq.empty()) {
		pair<ll, pll> p = pq.top();
		pq.pop();
		ll edgeweight = p.F, x = p.S.F, y = p.S.S;
		if (findParent(x, parentArr) != findParent(y, parentArr)) {
			merge(x, y, rankArr, parentArr);
			cost += edgeweight;
		}
	}


	deb(cost);

	auto stop1 = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop1 - start1);
#ifndef ONLINE_JUDGE
	cout << "Time: " << duration.count() / 1000 << " ms" << endl;
#endif
	return 0;
}