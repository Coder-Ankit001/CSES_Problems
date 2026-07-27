#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;

    vector<int> nums(n);
    for(int i=0; i<n; i++){
        cin >> nums[i];
    }

    vector<int> dec(n, 1), inc(n, 1);
    set<int> st1, st2;
    int maxRange = 1;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(nums[i] > nums[j] && dec[j] < 1 + dec[i]){
                dec[j] = 1 + dec[i];
                maxRange = max(maxRange, dec[j]);
            }
            if(nums[i] < nums[j] && inc[j] < 1 + inc[i]){
                inc[j] = 1 + inc[i];
                maxRange = max(maxRange, inc[j]);
            }
        }
    }

    for(int i=0; i<n; i++){
        cout << inc[i] << " " << dec[i] << "\n";
    }

    cout << maxRange << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("io/input.txt", "r", stdin);
    freopen("io/output.txt", "w", stdout);

    solve();

    return 0;
}