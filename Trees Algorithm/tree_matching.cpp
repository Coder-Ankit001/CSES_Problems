#include <bits/stdc++.h>
using namespace std;

bool dfs(int node, int par, vector<vector<int>>& tree, int& ans){
    bool hasLeaf = false;
    for(auto nei: tree[node]){
        if(nei == par) continue;
        if(dfs(nei, node, tree, ans)){
            hasLeaf = true;
        }
    }
    if(hasLeaf) {
        ans++;
        return false;
    }
    return true;
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

    int ans = 0;
    dfs(1, -1, tree, ans);
    cout << ans << endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    solve();

    return 0;
}