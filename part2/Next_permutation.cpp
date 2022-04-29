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
template <typename T> istream& operator>>(istream& in, vector<T>& a) {  for (T& x : a) in >> x;     return in; }
int main()
{  
    int n;cin>>n;
    vi a(n);
    cin>>a;
    int lidx=-1;
    for(int i=n-2;i>=0;i--){
        if(a[i]<a[i+1]){
            lidx=i;
            break;
        }
    }
    // if(lidx==-1){
    //     cout<<"do something"<<endl;
    // }
    int ridx=-1;
    if(lidx!=-1){
    for(int i=n-1;i>=0;i--){
        if(a[lidx]<a[i]){
            ridx=i;
            break;
        }
    }
    swap(a[lidx],a[ridx]);
    }
    reverse(a.begin()+lidx+1,a.end());
    for(auto i : a){
        cout<<i<<" ";
    }
    return 0;
    
}
/*5
1 4 2
7 6

1 4 6 2 7 */
/* 10
12 5 3 13 78 18 90 55 23 56

12 5 3 13 78 18 90 55 56 23 */
