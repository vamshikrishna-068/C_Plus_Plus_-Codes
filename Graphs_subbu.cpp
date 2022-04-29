#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define ff first
#define ss second
#define pii pair<int,int>
#define vii vector<pii>
#define ll long long
#define pb push_back
void dfs(vector<vector<int>> &adj, int u, vector<int> &vis){
    vis[u] = 1;
    cout << u << "\n";
    for(int v:adj[u]){
        if(!vis[v]){
            dfs(adj, v, vis);
        }
    }
}



void bfs(vector<vector<int>> &adj, int u, vector<int> &vis){
    queue<int> q;
    q.push(u);
    vis[u]=1;
    while(q.size()){
        u = q.front();
        q.pop();
        cout << u << " ";
        for(int v:adj[u]){
            if(!vis[v]){
                vis[v]=1;
                q.push(v);
            }
        }
    }
}


void solve(ll test){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n+1);
    for(int i=0;i<m;i++){
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    vector<int> vis(n+1, 0);
    // dfs(adj, 1, vis);
    bfs(adj, 1, vis);
}
int main(){

    solve(1);
    return 0;
}