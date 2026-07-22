#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve(){
    int n;
    cin >> n;
    vector<pair<int, int>> tasks(n);
    for(auto& it: tasks) {
        int dur, ddl;
        cin >> dur >> ddl;
        it = {dur, ddl};
    }

    sort(tasks.begin(), tasks.end());

    ll time = 0, reward = 0;
    for(int i=0; i<n; i++){
        time += tasks[i].first;
        reward += tasks[i].second - time;
    }

    cout << reward << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    solve();
    return 0;
}