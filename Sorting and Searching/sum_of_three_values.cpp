#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve(){
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> nums(n);
    for(int i=0; i<n; i++){
        int num;
        cin >> num;
        nums[i] = {num, i};
    }

    sort(nums.begin(), nums.end());


    bool found = false;
    for(int i=0; i<n-2; i++){
        if(i > 0 && nums[i].first == nums[i-1].first) continue;
        ll first = nums[i].first;
        int l = i+1, r = n-1;
        while(l < r){
            ll second = nums[l].first;
            ll third = nums[r].first;
            if(first + second + third == k){
                vector<int> temp = {nums[i].second + 1, nums[l].second + 1, nums[r].second + 1};
                sort(temp.begin(), temp.end());
                for(auto& it: temp) cout << it << " ";
                cout << endl;
                found = true;
                break;
            }
            if(first + second + third < k) l++;
            else r--;
        }
        if(found) break;
    }
    if(!found) cout << "IMPOSSIBLE" << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    solve();
    return 0;
}