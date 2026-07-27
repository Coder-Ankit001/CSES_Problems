#include <bits/stdc++.h>
using namespace std;

using ll = long long;

class DisjointSet{
    vector<int> parent, size;
    public:
    int largestComp, countComp;
    DisjointSet(int n){
        parent.resize(n+1, 0);
        size.resize(n+1, 1);
        for(int i=0; i<=n; i++) parent[i] = i;
        largestComp = 1;
        countComp = n;
    }
    int findParent(int node){
        if(parent[node] == node) return node;
        return parent[node] = findParent(parent[node]);
    }
    void unionBySize(int u, int v){
        int parU = findParent(u);
        int parV = findParent(v);

        if(parent[parU] == parent[parV]) return;
        if(size[parU] >= size[parV]){
            size[parU] += size[parV];
            parent[parV] = parU;
            largestComp = max(largestComp, size[parU]);
            countComp--;
        }
        else{
            size[parV] += size[parU];
            parent[parU] = parV;
            largestComp = max(largestComp, size[parV]);
            countComp--;
        }
    }
};
void solve(){
    int n, m;
    cin >> n >> m;

    DisjointSet ds(n);
    for(int i=0; i<m; i++){
        int u, v;
        cin >> u >> v;
        if(ds.findParent(u) != ds.findParent(v)){
            ds.unionBySize(u, v);
        }
        cout << ds.countComp << " " << ds.largestComp << endl;
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