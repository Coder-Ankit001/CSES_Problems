#include <bits/stdc++.h>
using namespace std;

int INF = 1e9;
void findSum(int ind, int sum, vector<int>& nums, vector<vector<bool>>& vis, unordered_set<int>& st, int n){
    if(ind >= n){
        st.insert(sum);
        vis[ind][sum] = 1;
        return;
    }
    if(vis[ind][sum]) return;
    vis[ind][sum] = 1;
    st.insert(sum);
    findSum(ind+1, sum+nums[ind], nums, vis, st, n);
    findSum(ind+1, sum, nums, vis, st, n);
}
void solve(){
    int n;
    cin >> n;

    int sum = 0;
    vector<int> nums(n);
    for(int i=0; i<n; i++){
        cin >> nums[i];
        sum += nums[i];
    }

    unordered_set<int> st;
    vector<vector<bool>> vis(n+1, vector<bool>(sum+1, false));
    findSum(0, 0, nums, vis, st, n);

    vector<int> res;
    res.reserve(st.size());
    for(auto it: st){
        if(it == 0) continue;
        res.push_back(it);
    }
    sort(res.begin(), res.end());
    cout << res.size() << endl;
    for(auto& it: res) cout << it << " ";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen("io/input.txt", "r", stdin);
    // freopen("io/output.txt", "w", stdout);

    solve();

    return 0;
}