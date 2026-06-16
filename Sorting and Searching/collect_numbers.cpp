#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
    #define debug(x) cerr << #x <<" = "<< x << "\n";
#else
    #define debug(x)
#endif

void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void solve(){
    int n;
    cin >> n;

    vector<int> arr(n);
    for(auto& it: arr) cin >> it;

    vector<int> pos(n+1);
    for(int i=0; i<n; i++) pos[arr[i]] = i;

    int res = 1;
    for(int i=1; i<n; i++){
        if(pos[i] > pos[i+1]) res++;
    }
    cout << res;
}

int main(){
    fast_io();
    
    solve();
    
    return 0;
}