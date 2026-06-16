#include <bits/stdc++.h>
using namespace std;

using ll = long long;
void solve(){
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];

    int i = 0, j = 0;
    map<int, int> mp;
    ll count = 0;
    while(j < n){
        mp[arr[j]]++;
        while((int)mp.size() != j-i+1){
            if(mp[arr[i]] == 1) mp.erase(arr[i]);
            else mp[arr[i]]--;
            i++;
        }
        count += (j - i + 1);
        j++;
    }
    cout << count << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    solve();
    return 0;
}