#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 1e9 + 7;
const int PRIME = 53;

vector<int> buildLPS(string& p){
    int n = p.size();
    vector<int> lps(n);
    int i = 1, j = 0;
    while(i< n){
        if(p[i] == p[j]){
            ++j;
            lps[i] = j;
            ++i;
        }
        else{
            if(j != 0) j = lps[j-1];
            else lps[i++] = 0;
        }
    }
    return lps;
}
void solve(){
    string s, p;
    cin >> s >> p;

    int n = p.size();
    int m = s.size();

    if(n > m){
        cout << 0 << "\n";
        return;
    }

    vector<int> lps = buildLPS(p);

    int i = 0, j = 0;
    int count = 0;
    while(i < m){
        if(s[i] == p[j]) {
            ++j; ++i;
        }
        else{
            if(j == 0)  i++;
            else j = lps[j-1];
        }
        if(j == n){
            count++;
            j = lps[j-1];
        }
    }
    cout << count << endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen("io/input.txt", "r", stdin);
    // freopen("io/output.txt", "w", stdout);

    solve();

    return 0;
}