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

void solve() {
    int n;
    cin >> n;

    vector<int> start(n);
    vector<int> ends(n);
    for(int i=0; i<n; i++){
        int st, end;
        cin >> st >> end;
        start[i] = st;
        ends[i] = end;
    }

    sort(start.begin(), start.end());
    sort(ends.begin(), ends.end());

    int ans = 0;
    int cnt = 0;
    int l = 0, r = 0;
    while(l < n && r < n){
        if(start[l] <= ends[r]){
            cnt++;
            l++;
            ans = max(ans, cnt);
        }
        else{
            cnt--;
            r++;
            ans = max(ans, cnt);
        }
    }

    cout << ans << endl;
}

int main(){
    fast_io();

    solve();
    return 0;
}