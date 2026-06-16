#include <bits/stdc++.h>
using namespace std;

using ll = long long;

class SegmentTree{
    vector<int> seg;
    public:
    SegmentTree(int n){
        seg.resize(4*n + 2);
        buildTree(0, n-1, 0);
    }

    // Remaining Elements
    int getSize(){ return seg[0]; }

    // Build Tree
    void buildTree(int lo, int hi, int ind){
        if(lo == hi){
            seg[ind] = 1;
            return;
        }

        int mid = (lo + hi) >> 1;
        buildTree(lo, mid, 2*ind+1);
        buildTree(mid+1, hi, 2*ind+2);

        seg[ind] = seg[2*ind+1] + seg[2*ind+2];
    }

    // Point Update
    void update(int lo, int hi, int node, int ind){
        if(lo == hi){
            seg[ind] = 0;
            return;
        }
        int mid = (lo + hi) >> 1;
        if(node <= mid) update(lo, mid, node, 2*ind+1);
        else update(mid+1, hi, node, 2*ind+2);
        seg[ind] = seg[2*ind+1] + seg[2*ind+2];
    }

    // Find index of kth alive element
    int query(int lo, int hi, int k, int ind){
        if(lo == hi) return lo;

        int mid = (lo + hi) >> 1;
        // Move Left when k <= leftCount
        int leftCount = seg[2*ind+1];
        if(k <= leftCount) return query(lo, mid, k, 2*ind+1);
        // Move Right when k > leftCount
        else return query(mid+1, hi, k-leftCount, 2*ind+2);
    }
};


class FenwickTree{
    int n;
    vector<int> fen;

    public:
    FenwickTree(int n){
        this->n = n;
        fen.resize(n+1);
        for(int i=1; i<=n; i++) update(i, 1);
    }

    int getSize() { return query(n); }

    int query(int ind){
        int sum = 0;
        while(ind > 0){
            sum += fen[ind];
            ind -= ind & (-ind);
        }
        return sum;
    }

    void update(int ind, int val){
        while(ind <= n){
            fen[ind] += val;
            ind += ind & (-ind);
        }
    }

    int findKth(int val){
        int cur = 0, prevSum = 0;
        for(int i = 20; i >= 0; i--){
            int next = cur + (1 << i);

            if(next <= n && fen[next] + prevSum < val){
                cur = next;
                prevSum += fen[next];
            }
        }
        return (cur + 1);
    }
};

void solve(){
    int n, k;
    cin >> n >> k;

    // SegmentTree st(n);
    // int pos = 0;
    // while(st.getSize() > 0){
    //     int size = st.getSize();
    //     pos = (pos + k) % size;
    //     int index = st.query(0, n-1, pos+1, 0);
    //     cout << index + 1 << " ";
    //     st.update(0, n-1, index, 0);
    // }

    FenwickTree ft(n);
    int pos = 0;
    while(ft.getSize() > 0){
        int cur_size = ft.getSize();
        pos = (pos + k) % cur_size;
        int index = ft.findKth(pos+1);
        ft.update(index, -1);
        cout << index << " ";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    solve();

    return 0;
}