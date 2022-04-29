 #include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define ff first
#define ss second
#define pii pair<int,int>
#define vii vector<pii>
#define ll long long
#define pb push_back
const int N=1e5+2,MOD=1e9+7;
const int INF=1e9+2;
void change(vector<vector<char>> &A, int x, int y){
	A[x][y]='*';
	int dx[]={0,0,-1,1};  // these are same as (0,1),(0,-1),(-1,0),(1,0) f
	int dy[]={1,-1,0,0}; // four sides of (0,0)
	for(int i=0;i<4;i++){
		int cx=x+dx[i];
		int cy=y+dy[i];
		if(cx>=0  && cx<A.size() && cy>=0 && cy<A[0].size() && A[x][y]=='O'){
			change(A,cx,cy);
		}
	}

}
int main(){
	int n,m;cin>>n>>m;
	vector<vector<char>> A(n,vector<char> (m));
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>A[i][j];
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(i==0 || i==n-1 || j==0 || j==m-1 ){
				if(A[i][j]=='O'){
					change(A,i,j);
				}
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
		cout<<A[i][j];
		}
		cout<<endl;
	}
	// for(int i=0;i<n;i++){
	// for(int j=0;j<m;j++){
	// 	if(A[i][j]=='*')
	// 		A[i][j]='O';
	// 	}
	// }
	// 	for(int i=0;i<n;i++){
	// for(int j=0;j<m;j++){
	// 	cout<<A[i][j];
	// 	}
	// 	cout<<endl;
	// }
	
	return 0;
}
// i/p
// XXXX
// XOOX
// XXOX
// XOXX
// o/p
// XXXX
// XXXX
// XXXX
// XOXX