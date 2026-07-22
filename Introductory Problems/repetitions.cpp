#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve(){
    string s;
    cin >> s;

    int i = 0, res = 0;
    while(i < s.size()){
        int f = 1;
        while(i+1<s.size() && s[i] == s[i+1]){
            f++; i++;
        }
        i++;
        res = max(res, f);
    }
    cout << res << endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    solve();
    return 0;
}