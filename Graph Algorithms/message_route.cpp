#include <bits/stdc++.h>
using namespace std;

int dfs(int node, int par, vector<vector<int>>& adj, vector<int>& parent){
    parent[node] = par;
    for(auto nei: adj[node]){
        if(parent[nei] != -1){
            if(nei == par) continue;
            else return node;
        }
        int res = dfs(nei, node, adj, parent);
        if(res != -1) return res;
    } 
    return -1;
}
void solve(){
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n+1);
    for(int i=0; i<m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int last = -1;
    vector<int> parent(n+1, -1);
    for(int i=1; i<=n; i++){
        if(parent[i] != -1) continue;
        int res = dfs(i, -1, adj, parent);
        if(res != -1){
            last = res;
            break;
        }
    }

    if(last == -1) cout << "IMPOSSIBLE" << endl;
    else{
        vector<int> res;
        int node = last;
        while(parent[node] != -1){
            res.push_back(node);
            node = parent[node];
        }
        res.push_back(node);
        reverse(res.begin(), res.end());
        res.push_back(node);

        for(auto it: res) cout << it << " ";
        cout << endl;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("intput.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    solve();
    return 0;
}