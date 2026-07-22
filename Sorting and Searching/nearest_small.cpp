#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i=0; i<n; i++) cin >> nums[i];

    stack<int> st;
    vector<int> nse(n);
    nse[0] = -1;
    st.push(0);
    for(int i=1; i<n; i++){
        while(!st.empty() && nums[st.top()] >= nums[i]) st.pop();
        if(st.empty()) nse[i] = -1;
        else nse[i] = st.top();
        st.push(i);
    }

    for(int i=0; i<n; i++){
        cout << nse[i] + 1 << " ";
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