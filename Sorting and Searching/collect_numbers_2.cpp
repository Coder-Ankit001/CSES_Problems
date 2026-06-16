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
    int n, k;
    cin >> n >> k;

    vector<int> arr(n+1);
    vector<int> pos(n+1);
    for(int i=1; i<=n; i++) {
        cin >> arr[i];
        pos[arr[i]] = i;
    }


    int res = 1;
    for(int i=1; i<n; i++){
        if(pos[i] > pos[i+1]) res++;
    }

    int l, r;
    set<pair<int, int>> updatedPairs;
    while(k--){
        cin >> l >> r;
        if(arr[l]+1 <= n) updatedPairs.insert({arr[l], arr[l]+1});
        if(arr[l]-1 >= 1) updatedPairs.insert({arr[l]-1, arr[l]});
        if(arr[r]+1 <= n) updatedPairs.insert({arr[r], arr[r]+1});
        if(arr[r]-1 >= 1) updatedPairs.insert({arr[r]-1, arr[r]});
        for(auto it: updatedPairs){
            res -= pos[it.first] > pos[it.second];
        }
        swap(arr[l], arr[r]);
        pos[arr[l]] = l;
        pos[arr[r]] = r;
        for(auto it: updatedPairs){
            res += pos[it.first] > pos[it.second];
        }

        cout << res << endl;
        updatedPairs.clear();
    }

}

int main(){
    fast_io();
    
    solve();
    
    return 0;
}