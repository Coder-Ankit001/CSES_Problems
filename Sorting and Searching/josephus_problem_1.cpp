#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int MOD = (int)(1e9 + 7);

void solve(){
    int n;
    cin >> n;

    queue<int> q;
    for(int i=1; i<=n; i++) q.push(i);

    bool pick = false;
    while(!q.empty()){
        if(pick){
            cout << q.front() << endl;
            q.pop();
        }
        else{
            q.push(q.front());
            q.pop();
        }
        pick = 1 - pick;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    solve();

    return 0;
}