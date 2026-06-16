#include <bits/stdc++.h>
using namespace std;

using ll = long long;

vector<vector<int>> dp;
vector<int> tree;
int LOG;

void kthAncestor(int n){
    LOG = log2(n) + 1;
    dp.resize(n+1, vector<int>(LOG, -1));

    for(int i=2; i<=n; i++){
        dp[i][0] = tree[i];
    }
    for(int j=1; j<LOG; j++){
        for(int i=1; i<=n; i++){
            int par = dp[i][j-1];
            if(par != -1){
                dp[i][j] = dp[par][j-1];
            }
        }
    }
}

int binaryLift(int node, int k){
    for(int i=0; i<LOG; i++){
        if((k>>i) & 1){
            node = dp[node][i];
            if(node == -1) break;
        }
    }
    return node;
}
void solve(){
    int n, q;
    cin >> n >> q;

    tree.resize(n+1, -1);
    for(int i=2; i<=n; i++){
        int par;
        cin >> par;
        tree[i] = par;
    }

    kthAncestor(n);

    for(int i=0; i<q; i++){
        int node, k;
        cin >> node >> k;
        int res = binaryLift(node, k);
        cout << res << " ";
    }
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