#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 1e9 + 7;
const int PRIME = 31;

string boothAlgo(string& s, int n){
    string s2 = s + s;

    int i = 0, j = 1, k = 0;
    while(i < n && j < n){
        if(s2[i+k] == s2[j+k]) ++k;
        else{
            if(s2[i+k] > s2[j+k]) i += k + 1;
            else j += k + 1;
            if(i == j) j++;
            k = 0;
        }
    }
    return s2.substr(min(i, j), n);
}

void solve(){
    string s;
    cin >> s;

    int n = s.size();
    cout <<  boothAlgo(s, n) << "\n";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen("io/input.txt", "r", stdin);
    // freopen("io/output.txt", "w", stdout);

    solve();

    return 0;
}