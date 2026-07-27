#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 1e9 + 7;
const int PRIME = 31;


string manacher(string s) {
    string t = "#";
    for(char c : s) {
        t += c;
        t += '#';
    }

    int n = t.size();
    t = "$" + t + "^";

    vector<int> p(n + 2);

    int l = 0, r = 1;
    int maxRad = 0, maxInd = -1;
    for(int i = 1; i <= n; i++) {
        if(i <= r)
            p[i] = min(r - i, p[l + (r - i)]);

        while(t[i - p[i]] == t[i + p[i]])
            p[i]++;

        if(i + p[i] > r) {
            l = i - p[i];
            r = i + p[i];
        }
        if(maxRad < p[i]){
            maxRad = p[i];
            maxInd = i;
        }
    }

    int st = maxInd - (maxRad - 1);
    int end = maxInd + (maxRad - 1);
    string res = "";
    for(int i=st; i<=end; i++){
        if(t[i] != '#') res += t[i];
    }
    return res;
}
void solve(){
    string s;
    cin >> s;

    int n = s.size();
    cout << manacher(s) << "\n";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen("io/input.txt", "r", stdin);
    // freopen("io/output.txt", "w", stdout);

    solve();

    return 0;
}