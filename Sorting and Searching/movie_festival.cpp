#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
    #define debug(x) cerr << #x <<" = "<< x << "\n";
#else
    #define debug(x)
#endif  

void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

bool comp(vector<int>& a , vector<int>& b){
    return a[1] < b[1];
}
void solve() {
    int n;
    cin >> n;

    vector<vector<int>> time(n);
    for(int i=0; i<n; i++){
        int st, end;
        cin >> st >> end;
        time[i] = {st, end};
    }

    sort(time.begin(), time.end(), comp);

    int cnt = 0;
    int timer = -1;
    for(int i=0; i<n; i++){
        if(timer <= time[i][0]){
            timer = time[i][1];
            cnt++;
        }
    }

    cout << cnt << endl;
}

int main(){
    fast_io();

    solve();
    return 0;
}