#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve(){
    int n;
    cin >> n;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            // Top Right
            int tr = (i+1) * (n-j) - 1;
            if(i+1 >= 3) tr--;
            if(n-j >= 3) tr--;

            // Top
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    solve();
    return 0;
}