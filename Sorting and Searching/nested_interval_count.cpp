#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct Interval{
    int i, j, idx;
};

class Fenwick{
    vector<int> fen;
    int n;

    public:
    Fenwick(int n): n(n){ fen.resize(n+1); }
    void update(int idx, int val){
        while(idx <= n){
            fen[idx] += val;
            idx += (idx) & (-idx);
        }
    }
    int query(int idx){
        int sum = 0;
        while(idx > 0){
            sum += fen[idx];
            idx -= (idx) & (-idx);
        }
        return sum;
    }
};

void solve(){
    int n;
    cin >> n;

    vector<Interval> arr(n);
    vector<int> vals;
    for(int i=0; i<n; i++){
        int x, y;
        cin >> x >> y;
        arr[i] = {x, y, i};
        vals.push_back(y);
    }

    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());
    auto get = [&](int x){
        return lower_bound(vals.begin(), vals.end(), x) - vals.begin() + 1;
    };

    sort(arr.begin(), arr.end(), [](auto& a, auto& b){ return a.i == b.i? a.j > b.j: a.i < b.i; });

    vector<int> contains(n), contained(n);

    Fenwick ft(vals.size());
    for(int i=n-1; i>=0; i--){
        int y = get(arr[i].j);
        contains[arr[i].idx] = ft.query(y);
        ft.update(y, 1);
    }

    ft = Fenwick(vals.size());

    for(int i=0; i<n; i++){
        int y = get(arr[i].j);
        contained[arr[i].idx] = i - ft.query(y-1);
        ft.update(y, 1);
    }

    for (int i = 0; i < n; i++)
        cout << contains[i] << " ";
    cout << "\n";

    for (int i = 0; i < n; i++)
        cout << contained[i] << " ";
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    solve();

    return 0;
}