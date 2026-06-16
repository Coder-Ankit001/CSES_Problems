#include <bits/stdc++.h>
using namespace std;

int dfs(int node, int par, vector<set<int>>& tree, vector<int>& res){
    int count = 0;
    for(auto nei: tree[node]){
        if(nei == par || nei == node) continue;
        count += 1 + dfs(nei, node, tree, res);
    }
    return res[node] = count;
}
void solve(){
    int n;
    cin >> n;
    vector<set<int>> tree(n+1);
    for(int i=2; i<=n; i++){
        int par;
        cin >> par;
        tree[par].insert(i);
        tree[i].insert(par);
    }

    vector<int> res(n+1);
    dfs(1, -1, tree, res);
    for(int i=1; i<=n; i++) cout << res[i] << " ";
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