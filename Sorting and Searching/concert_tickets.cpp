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
    int n, m;
    cin >> n >> m;

    multiset<ll> tick;
    for(int i=0; i<n; i++){
        ll val;
        cin >> val;
        tick.insert(val);
    }
    for(int i=0; i<m; i++) {
        ll val;
        cin >> val;
        
        auto it = tick.upper_bound(val);

        if(it == tick.begin()){
            cout << "-1 ";
            continue;
        }
        else{
            --it;
            cout << *it <<" ";
            tick.erase(it);
        }
    }
    cout << "\n";
}


int main(){
    fast_io();

    int t = 1;
    while (t--) solve();
    return 0;
}