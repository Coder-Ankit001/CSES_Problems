#include <bits/stdc++.h>
using namespace std;

using ll = long long;

class SegmentTree{
    vector<ll> seg;
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
        seg[ind] = (ll)max(seg[2*ind+1], seg[2*ind+2]);
    }

    // Updates
    void pointUpdate(int ind, int lo, int hi, int i, ll del){
        if(lo == hi){
            seg[ind] += del;
            return;
        }

        int mid = lo + (hi - lo) / 2;
        if(i <= mid) pointUpdate(2*ind+1, lo, mid, i, del);
        else pointUpdate(2*ind+2, mid+1, hi, i, del);

        seg[ind] = (ll)max(seg[2*ind+1], seg[2*ind+2]);
    }

    void update(int i, ll del){
        pointUpdate(0, 0, n-1, i, del);
    }

    // Queries
    int findLowerBound(ll val){
        int res = -1;
        int lo = 0, hi = n-1, ind = 0;
        while(lo < hi){
            int mid = lo + (hi - lo) / 2;
            int leftChild = 2 * ind + 1;
            int rightChild = 2 * ind + 2;
            if(seg[leftChild] >= val){
                ind = leftChild;
                hi = mid;
            }
            else{
                ind = rightChild;
                lo = mid + 1;
            }
        }
        return (seg[ind] >= val) ? lo : -1;
    }
    int query(ll val){
        return findLowerBound(val);
    }
};

void solve(){
    int n, q;
    cin >> n >> q;

    vector<int> nums(n);
    for(auto& it: nums) cin >> it;

    SegmentTree st(nums);
    for(int i=0; i<q; i++){
        int group;
        cin >> group;
        int ind =  st.query(group);
        if(ind != -1) st.update(ind, -group);
        cout << ind + 1 << endl;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("./io/input.txt", "r", stdin);
    freopen("./io/output.txt", "w", stdout);

    solve();

    return 0;
}