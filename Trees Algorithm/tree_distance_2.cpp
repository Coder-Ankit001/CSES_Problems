#include <bits/stdc++.h>
using namespace std;

using ll = long long;

vector<ll> dp, child;
void dfs(int node, int par, vector<vector<int>>& tree){
    dp[node] = 0; child[node] = 1;
    for(auto nei: tree[node]){
        if(par == nei) continue;
        dfs(nei, node, tree);
        child[node] += child[nei];
        dp[node] += dp[nei] + child[nei];
    }
}

void reroot(int node, int par, int n, vector<vector<int>>& tree, vector<ll>& dist){
    for(auto nei: tree[node]){
        if(par == nei) continue;
        dist[nei] = dist[node] - child[nei] + (n - child[nei]);
        reroot(nei, node, n, tree, dist);
    }
}


void solve(){
    int n;
    cin >> n;

    vector<vector<int>> tree(n+1);
    for(int i=1; i<n; i++){
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    dp.resize(n+1); child.resize(n+1);
    dfs(1, -1, tree);

    vector<ll> dist(n+1);
    dist[1] = dp[1];
    reroot(1, -1, n, tree, dist);

    for(int i=1; i<=n; i++) cout << dist[i] << " ";
    cout << endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    solve();

    return 0;
}