#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve(){
    int n;
    cin >> n;
    if(n == 1){
        cout << 1 << endl;
        return;
    }
    if(n == 3 || n == 2){
        cout << "NO SOLUTION" << endl;
        return;
    }
    if(n == 4){
        cout << "2 4 1 3" << endl;
        return;
    }

    vector<int> v(n);
    int num = 1;
    for(int i=0; i<n; i+=2) v[i] = num++;
    for(int i=1; i<n; i+=2) v[i] = num++;

    for(int i=0; i<n; i++){
        cout << v[i] << " ";
    }
    cout << endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    solve();
    return 0;
}