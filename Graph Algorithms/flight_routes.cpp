#include <bits/stdc++.h>
using namespace std;

using ll = long long;
ll INF = 1e17;

void solve(){
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<pair<int, ll>>> adj(n+1);
    for(int i=0; i<m; i++){
        int u, v, wt;
        cin >> u >> v >> wt;
        adj[u].push_back({v, wt});
    }

    vector<ll> res;
    vector<int> count(n+1);
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;
    pq.push({0LL, 1});
    while(!pq.empty()){
        auto [steps, node] = pq.top(); pq.pop();

        if(count[node] >= k) continue;
        count[node]++;

        if(node == n)
            res.push_back(steps);

        for(auto [nei, wt]: adj[node]){
            if(count[nei] < k){
                pq.push({steps+wt, nei});
            }
        }
    }

    sort(res.begin(), res.end());
    for(auto it: res){
        cout << it << " ";
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    solve();
    return 0;
}