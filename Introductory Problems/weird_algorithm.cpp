#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve(){
    ll n;
    cin >> n;

    while(n != 1){
        cout << n << " ";
        if(n % 2) n = (n * 3) + 1;
        else n /= 2;
    }
    cout << n << endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    solve();
    return 0;
}