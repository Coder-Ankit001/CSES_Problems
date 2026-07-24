#include <bits/stdc++.h>
using namespace std;


class SegmentTree{
    vector<int> seg;
    int n;

    public:
    SegmentTree(vector<int>& nums){
        this->n = nums.size();
        seg.resize(4*n+1, 0);
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
        seg[ind] = (seg[2*ind+1] ^ seg[2*ind+2]);
    }

    // // Updates
    // void pointUpdate(int ind, int lo, int hi, int i, int val){
    //     if(lo == hi){
    //         seg[ind] = val;
    //         return;
    //     }

    //     int mid = lo + (hi - lo) / 2;
    //     if(i <= mid) pointUpdate(2*ind+1, lo, mid, i, val);
    //     else pointUpdate(2*ind+2, mid+1, hi, i, val);

    //     seg[ind] = min(seg[2*ind+1], seg[2*ind+2]);
    // }

    // void update(int i, int val){
    //     pointUpdate(0, 0, n-1, i, val);
    // }

    // Queries
    int findXOR(int ind, int lo, int hi, int l, int r){
        // Out of Range
        if(r < lo || l > hi) return 0;

        // Lie in Range
        if(l <= lo && r >= hi) return seg[ind];

        // Partially Lie
        int mid = lo + (hi - lo) / 2;
        int left = findXOR(2*ind+1, lo, mid, l, r);
        int right = findXOR(2*ind+2, mid+1, hi, l, r);
        return (left ^ right);
    }

    int query(int l, int r){
        return findXOR(0, 0, n-1, l, r);
    }
};

void solve(){
    int n, q;
    cin >> n >> q;

    vector<int> nums(n);
    for(auto& it: nums) cin >> it;

    SegmentTree st(nums);
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