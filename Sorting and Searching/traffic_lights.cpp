#include <bits/stdc++.h>
using namespace std;


void solve(){
    int x, n;
    cin >> x >> n;

    set<int> st;
    st.insert(0); st.insert(x);
    multiset<int> mst;
    mst.insert(x);
    for(int i=0; i<n; i++){
        int val;
        cin >> val;
        int ub = *st.upper_bound(val);
        int lb = 0;
        auto it = st.lower_bound(val);
        if(it != st.begin()){
            it--;
            lb = *it;
        }
        mst.erase(mst.find(ub-lb));
        mst.insert(val-lb);
        mst.insert(ub-val);
        st.insert(val);
        cout << *mst.rbegin() << " ";
    }
    cout << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    solve();
    return 0;
}