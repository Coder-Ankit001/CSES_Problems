#include <bits/stdc++.h>
using namespace std;

vector<int> parent, depth;
vector<int> counter;
vector<vector<int>> dp;
int LOG;
void findKthAncestor(int n){
    LOG = log2(n+1) + 1;
    dp.resize(n+1, vector<int>(LOG, -1));

    for(int node=1; node<=n; node++) dp[node][0] = parent[node];

    for(int k=1; k<LOG; k++){
        for(int node=1; node<=n; node++){
            int prev = dp[node][k-1];
            if(prev == -1) continue;
            dp[node][k] = dp[prev][k-1];
        }
    }
}

int getLCA(int u, int v){
    if(depth[u] < depth[v]) swap(u ,v);
    

    int diff = depth[u] - depth[v];
    for(int bit=LOG-1; bit>=0; bit--){
        if(diff & (1 << bit)){
            u = dp[u][bit];
        }
    }

    if(u == v) return u;

    for(int bit=LOG-1; bit>=0; bit--){
        if(dp[u][bit] != dp[v][bit]){
            u = dp[u][bit];
            v = dp[v][bit];
        }
    }
    return dp[u][0];
}

void query(int u, int v){
    int lca = getLCA(u, v);
    counter[u]++; 
    counter[v]++;
    counter[lca]--;
    if(parent[lca] != -1) counter[parent[lca]]--;
}

void dfs(int node, int par, int d, vector<vector<int>>& tree){
    parent[node] = par;
    depth[node] = d;
    for(auto nei: tree[node]){
        if(nei == par) continue;
        dfs(nei, node, d+1, tree);
    }
}

int dfs2(int node, int par, vector<vector<int>>& tree){
    int curCount = counter[node];
    for(auto nei: tree[node]){
        if(nei == par) continue;
        curCount += dfs2(nei, node, tree);
    }
    return counter[node] = curCount;
}

void solve(){
    int n, q;
    cin >> n >> q;

    vector<vector<int>> tree(n+1);
    for(int i=1; i<n; i++){
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    
    parent.resize(n+1);
    depth.resize(n+1);
    dfs(1, -1, 0, tree);

    findKthAncestor(n);

    counter.resize(n+1);
    
    for(int i=0; i<q; i++){
        int u, v;
        cin >> u >> v;
        query(u, v);
    }
    dfs2(1, -1, tree);

    for(int i=1; i<=n; i++) cout << counter[i] << " ";
    cout << endl;
}

int main(){
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    solve();

    return 0;
}