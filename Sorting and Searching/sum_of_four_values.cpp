#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve(){
    int n, k;
    cin >> n >> k;
    vector<pair<ll, int>> nums(n);
    for(int i=0; i<n; i++){
        ll num;
        cin >> num;
        nums[i] = {num, i+1};
    }

    sort(nums.begin(), nums.end());


    bool found = false;
    for(int i=0; i<n-3; i++){
        if(i>0 && nums[i].first == nums[i-1].first) continue;
        auto[first, firstInd] = nums[i];
        for(int j=i+1; j<n-2; j++){
            if(j > i+1 && nums[j].first == nums[j-1].first) continue;
            auto[second, secondInd] = nums[j];
            int l = j+1, r = n-1;
            while(l < r){
                auto[third, thirdInd] = nums[l];
                auto[fourth, fourthInd] = nums[r];
                if(first + second + third + fourth == k){
                    vector<int> temp = {firstInd, secondInd, thirdInd, fourthInd};
                    sort(temp.begin(), temp.end());
                    for(auto& it: temp) cout << it << " ";
                    cout << endl;
                    found = true;
                    break;
                }
                if(first + second + third + fourth < k) l++;
                else r--;
            }
            if(found) break;
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