#include <bits/stdc++.h>
using namespace std;

int INF = 1e9;
void buildTable(vector<array<int, 31>>& dp, vector<int>& parent, int n){
    int LOG = 30;
    
    for(int node=1; node<=n; node++) dp[node][0] = parent[node];

    for(int k=1; k<=LOG; k++){
        for(int node=1; node<=n; node++){
            int mid = dp[node][k-1];
            dp[node][k] = dp[mid][k-1];
        }
    }
}

int query(int node, int k, vector<array<int, 31>>& dp, int n){
    int LOG = 30;
    for(int i=LOG; i>=0; i--){
        if(k & (1LL << i)){
            node = dp[node][i];
        }
    }
    return node;
}

void solve(){
    int n, q;
    cin >> n >> q;

    vector<int> parent(n+1);
    for(int i=1; i<=n; i++) cin >> parent[i];

    vector<array<int, 31>> dp(n + 1);
    buildTable(dp, parent, n);

    for(int i=0; i<q; i++){
        int node, k;
        cin >> node >> k;
        cout << query(node, k, dp, n) << "\n";
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen("io/input.txt", "r", stdin);
    // freopen("io/output.txt", "w", stdout);

    solve();
    return 0;
}