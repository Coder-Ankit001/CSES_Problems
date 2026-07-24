#include <bits/stdc++.h>
using namespace std;

using ll = long long;

class SegmentTree{
    vector<ll> seg, lazy;
    int n;
    public:
    SegmentTree(vector<int>& nums){
        this->n = nums.size();
        seg.resize(4*n+1, 0);
        lazy.resize(4*n+1, 0);
        buildTree(0, 0, n-1, nums);
    }

    void buildTree(int ind, int lo, int hi, vector<int>& nums){
        if(lo == hi){
            seg[ind] = nums[lo];
            return; 
        }

        int mid = lo + (hi - lo) / 2;
        buildTree(2*ind+1, lo, mid, nums);
        buildTree(2*ind+2, mid+1, hi, nums);
        seg[ind] = seg[2*ind+1] + seg[2*ind+2];
    }

    // Updates
    void pushUpdate(int ind, int lo, int hi){
        if(lazy[ind] != 0){
            seg[ind] += (hi - lo + 1) * lazy[ind];
            if(lo != hi){
                lazy[2*ind+1] += lazy[ind];
                lazy[2*ind+2] += lazy[ind];
            }
            lazy[ind] = 0;
        }
    }
    void lazyUpdate(int ind, int lo, int hi, int l, int r, ll del){
        // Update Backlog
        pushUpdate(ind, lo, hi);

        // Out of Range
        if(l > hi || r < lo) return;

        // Lie in Range
        if(l <= lo && hi <= r){
            seg[ind] += (hi - lo + 1) * del;
            if(lo != hi){
                lazy[2*ind+1] += del;
                lazy[2*ind+2] += del;
            }
            return;
        }

        int mid = lo + (hi - lo) / 2;
        lazyUpdate(2*ind+1, lo, mid, l, r, del);
        lazyUpdate(2*ind+2, mid+1, hi, l, r, del);

        seg[ind] = seg[2*ind+1] + seg[2*ind+2];
    }

    void update(int l, int r, int del){
        lazyUpdate(0, 0, n-1, l, r, del);
    }

    // Queries
    ll pointQuery(int ind, int lo, int hi, int i){
        // Update Backlog
        pushUpdate(ind, lo, hi);

        // Found Index
        if(lo == hi) return seg[ind];

        int mid = lo + (hi - lo) / 2;

        if(i <= mid) return pointQuery(2*ind+1, lo, mid, i);
        else return pointQuery(2*ind+2, mid+1, hi, i);
    }

    ll query(int i){
        return pointQuery(0, 0, n-1, i);
    }
};

void solve(){
    int n, q;
    cin >> n >> q;

    vector<int> nums(n);
    for(auto& it: nums) cin >> it;

    SegmentTree st(nums);
    for(int i=0; i<q; i++){
        int q1;
        cin >> q1;
        if(q1 == 1){
            int l, r, del;
            cin >> l >> r >> del;
            st.update(l-1, r-1, del);
        }
        else{
            int ind;
            cin >> ind;
            cout << st.query(ind-1) << endl;
        }
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