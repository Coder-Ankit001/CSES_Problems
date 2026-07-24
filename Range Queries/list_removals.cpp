#include <bits/stdc++.h>
using namespace std;

// class SegmentTree{
//     vector<int> seg;
//     int n;

//     public:
//     SegmentTree(vector<int>& nums){
//         this->n = nums.size();
//         seg.resize(4*n+1, 0);
//         buildTree(0, 0, n-1);
//     }

//     void buildTree(int ind, int lo, int hi){
//         if(lo == hi){
//             seg[ind] = 1;
//             return; 
//         }

//         int mid = lo + (hi - lo) / 2;
//         buildTree(2*ind+1, lo, mid);
//         buildTree(2*ind+2, mid+1, hi);
//         seg[ind] = seg[2*ind+1] + seg[2*ind+2];
//     }

//     // Updates
//     void pointUpdate(int ind, int lo, int hi, int i){
//         if(lo == hi){
//             seg[ind] = 0;
//             return;
//         }

//         int mid = lo + (hi - lo) / 2;
//         if(i <= mid) pointUpdate(2*ind+1, lo, mid, i);
//         else pointUpdate(2*ind+2, mid+1, hi, i);

//         seg[ind] = seg[2*ind+1] + seg[2*ind+2];
//     }

//     void update(int i){
//         pointUpdate(0, 0, n-1, i);
//     }

//     // Queries
//     int findLowerBound(int ind, int lo, int hi, int k){
//         if (lo == hi) return lo;

//         int mid = lo + (hi - lo) / 2;
//         int leftChild = 2 * ind + 1;
//         int rightChild = 2 * ind + 2;

//         if (seg[leftChild] >= k) {
//             return findLowerBound(leftChild, lo, mid, k);
//         } 
//         else {
//             return findLowerBound(rightChild, mid + 1, hi, k - seg[leftChild]);
//         }
//     }
//     int query(int k){
//         return findLowerBound(0, 0, n-1, k);
//     }
// };

class FenwickTree{
    vector<int> fen;
    int n;

    public:
    FenwickTree(int n){
        this->n = n;
        fen.resize(n+1, 0);
        initializeTree();
    }

    void initializeTree(){
        for(int i=0; i<n; i++) update(i, 1);
    }

    void update(int ind, int val){
        ind++;
        while(ind <= n){
            fen[ind] += val;
            ind += (ind & -ind);
        }
    }

    int findKth(int k) {
        int cur = 0, prevsum = 0;

        int max_pow = 1 << (31 - __builtin_clz(n));

        for (int i = max_pow; i > 0; i>>=1) {
            if (cur + i <= n && prevsum + fen[cur + i] < k) {
                cur += i;
                prevsum += fen[cur];
            }
        }
        return cur + 1;
    }

    int query(int ind){
        return findKth(ind) - 1;
    }
};

void solve(){
    int n;
    cin >> n;

    vector<int> nums(n);
    for(auto& it: nums) cin >> it;

    FenwickTree ft(n);
    for(int i=0; i<n; i++){
        int q;
        cin >> q;
        int ind = ft.query(q);
        if(ind != -1) {
            ft.update(ind, -1);
            cout << nums[ind] << " ";
        }
        else cout << -1 << " ";
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