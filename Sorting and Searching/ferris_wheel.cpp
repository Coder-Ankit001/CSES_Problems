#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) x.begin(), x.end()

void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void solve() {
    int n, wt;
    cin >> n >> wt;

    vector<ll> vec(n);
    for(auto& it: vec) cin >> it;

    sort(all(vec));

    if(vec[0] > wt){
        cout << "0" <<"\n";
        return;
    }

    int cnt = 0;
    int l = 0; int r = n-1;
    while(l < r){
        if(vec[l] + vec[r] <= wt){
            l++; r--; cnt++;
        }
        else{
            if(vec[r] <= wt) cnt++;
            r--;
        }
    }
    if(l == r && vec[l] <= wt) cnt++;
    cout << cnt << "\n";
}


int main(){
    fast_io();

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int t = 1;
    while (t--) solve();
    return 0;
}