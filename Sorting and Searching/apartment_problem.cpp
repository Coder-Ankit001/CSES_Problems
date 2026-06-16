#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
#define ppb pop_back

#ifndef ONLINE_JUDGE
    #define debug(x) cerr << #x <<" = "<< x << "\n";
#else
    #define debug(x)
#endif

const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LINF = 1e18;  

void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<ll> desire(n);
    for(auto& it: desire) cin >> it;
    vector<ll> size(m);
    for(auto& it: size) cin >> it;

    sort(all(desire));
    sort(all(size));

    int cnt = 0;
    int first = 0; int second = 0;
    while(first < n && second < m){
        ll req = desire[first];
        ll apart = size[second];
        if(req + k >= apart && req - k <= apart){
            first++; second++;
            cnt++;
        }
        else if(req + k < apart) first++;
        else second++;
    }
    cout << cnt << endl;
}


int main(){
    fast_io();

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int t = 1;
    while (t--) solve();
    return 0;
}