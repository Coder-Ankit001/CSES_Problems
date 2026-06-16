#include <bits/stdc++.h>
using namespace std;

struct Tuple{
    int id, st, end;
    Tuple(){}
    Tuple(int i, int s, int e): id(i), st(s), end(e) {}

};
static bool comp(Tuple& a, Tuple& b){
    if(a.st == b.st) return a.end <  b.end;
    return a.st < b.st;
}
void solve(){
    int n;
    cin >> n;

    vector<Tuple> cust(n);
    for(int i=0; i<n; i++){
        int v1, v2;
        cin >> v1 >> v2;
        cust[i] = Tuple(i, v1, v2);
    }

    sort(cust.begin(), cust.end(), comp);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    vector<int> res(n);
    int last_room = 0;
    for(int i=0; i<n; i++){
        if(pq.empty() || pq.top().first >= cust[i].st){
            last_room++;
            pq.push({cust[i].end, last_room});
            res[cust[i].id] = last_room;
        }
        else{
            pair<int, int> top = pq.top(); pq.pop();
            pq.push({cust[i].end, top.second});
            res[cust[i].id] = top.second;
        }
    }
    cout << last_room << endl;
    for(auto x: res) cout << x << " ";
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