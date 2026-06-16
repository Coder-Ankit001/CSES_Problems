#include <bits/stdc++.h>
using namespace std;
using ll = long long;

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

ll dp[20][11][2][2];

ll solve(int pos, int prev, int tight, int lz, vector<int>& d){
    if(pos == (int)d.size()) return 1;

    ll &memo = dp[pos][prev][tight][lz];
    if(memo != -1) return memo;

    int lim = tight ? d[pos] : 9;
    ll res = 0;

    for(int i = 0; i <= lim; ++i){
        int nt  = (tight && i == d[pos]) ? 1 : 0;
        int nlz = (lz && i == 0) ? 1 : 0;

        int nprev = prev;
        if(!nlz) nprev = i;

        if(!nlz && nprev == prev) continue;

        res += solve(pos + 1, nprev, nt, nlz, d);
    }

    return memo = res;
}

// ------------------------------------------- Func ----------------------------------------------- //
ll _func(ll a){
    if(a < 0) return 0;                   // safety for a-1 calls

    vector<int> d;
    if(a == 0) d.push_back(0);
    else {
        while(a){
            d.push_back(a % 10);
            a /= 10;
        }
        reverse(d.begin(), d.end());
    }

    memset(dp, -1, sizeof(dp));

    return solve(0, 10, 1, 1, d);
}


// ------------------------------------------- Main ----------------------------------------------- //
int main(){
    fast_io();

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    ll a, b;
    cin >> a >> b;

    cout << _func(b) - _func(a-1) << endl;
    return 0;
}