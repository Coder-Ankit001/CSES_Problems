#include <bits/stdc++.h>
using namespace std;


class SparseTable{
    vector<vector<int>> sparse;
    int n;
    public:
    SparseTable(vector<int>& nums){
        this->n = nums.size();
        int LOG = floor(log2(n));
        sparse.resize(LOG+1);
        buildTable(nums, LOG);
    }
    void buildTable(vector<int>& nums, int LOG){
        sparse[0] = nums;
        for(int i=1; i <= LOG; i++){
            int len = (1 << i);
            int half = (1 << (i-1));
            sparse[i].resize(n - len + 1);
            for(int j=0; j + (1 << i) <= n; j++){
                sparse[i][j] = min(sparse[i-1][j], sparse[i-1][j+half]);
            }
        }
    }

    int query(int l, int r){
        int p = 31 - __builtin_clz(r-l+1);
        return min(sparse[p][l], sparse[p][r - (1 << p) + 1]);
    }
};

void solve(){
    int n, q;
    cin >> n >> q;

    vector<int> nums(n);
    for(auto& it: nums) cin >> it;

    SparseTable st(nums);
    for(int i=0; i<q; i++){
        int l, r;
        cin >> l >> r;
        cout << st.query(l-1, r-1) << endl;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen("./io/input.txt", "r", stdin);
    // freopen("./io/output.txt", "w", stdout);

    solve();

    return 0;
}