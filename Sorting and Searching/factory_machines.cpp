#include <bits/stdc++.h>
using namespace std;

using ll = long long;

bool possible(ll maxTime, vector<ll>& arr, int n, ll k){
    ll totalCount = 0;
    for(int i=0; i<n; i++){
        totalCount += (maxTime / (ll)arr[i]);
        if(totalCount >= k) return true;
    }
    return false;
}
void solve(){
    ll n, k;
    cin >> n >> k;

    vector<ll> arr(n);
    
    for(auto& it: arr) cin >> it;
    sort(arr.begin(), arr.end());

    ll i = 0, j = 1e18;
    while(i <= j){
        ll mid = i + (j - i) / 2;
        if(possible(mid, arr, n, k)){
            j = mid - 1;
        }
        else i = mid + 1;
    }
    cout << i << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    solve();

    return 0;
}