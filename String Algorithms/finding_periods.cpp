#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 1e9 + 7;
const int PRIME = 31;

void solve(){
    string s;
    cin >> s;

    int n = s.size();

    vector<int> lps(n);
    int i = 1, j = 0;
    while(i < n){
        if(s[i] == s[j]){
            j++;
            lps[i] = j;
            i++;
        }
        else{
            if(j != 0){
                j = lps[j-1];
            }
            else{
                lps[i] = 0;
                i++;
            }
        }
    }
    cout << endl;


    int cur = lps[n-1];
    cout << n - cur << " ";
    while(cur != 0){
        cur = lps[cur-1];
        cout << n - cur << " ";
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen("io/input.txt", "r", stdin);
    // freopen("io/output.txt", "w", stdout);

    solve();

    return 0;
}