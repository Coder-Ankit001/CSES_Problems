#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve(){
    int n;
    cin >> n;
    vector<int> books(n);
    for(auto& it: books) cin >> it;

    sort(books.begin(), books.end());

    ll lastBook = books[n-1];
    ll sumOfBooks = (ll)accumulate(books.begin(), books.end() - 1, 0LL);

    if(lastBook <= sumOfBooks){
        cout << lastBook + sumOfBooks << endl;
    }
    else cout << 2 * lastBook << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    solve();
    return 0;
}