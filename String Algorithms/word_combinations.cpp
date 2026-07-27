#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

class Node{
    Node* nodes[26];
    bool end;
    public:
    Node(){
        for(int i=0; i<26; i++) nodes[i] = nullptr;
        end = false;
    }
    bool containsKey(char c){
        return nodes[c-'a'] != nullptr;
    }
    void put(char c, Node* a){
        nodes[c-'a'] = a;
    }
    Node* getKey(char c){
        return nodes[c-'a'];
    }
    void setEnd() { end = true; }
    bool isEnd() { return end; }
};

void insert(string& word, Node* root){
    Node* temp = root;
    for(auto c: word){
        if(!temp->containsKey(c)) temp->put(c, new Node());
        temp = temp->getKey(c);
    }
    temp->setEnd();
}

int countWays(int ind, string& s, Node* root, vector<int>& dp){
    Node* temp = root;
    int count = 0;
    for(int i=ind; i<s.size(); i++){
        if(!temp->containsKey(s[i])) break;
        temp = temp->getKey(s[i]);
        if(temp->isEnd()){
            count = (count + dp[i+1]) % MOD;
        }
    }
    return count;
}
void solve(){
    string s;
    cin >> s;
    
    Node* root = new Node();
    int n;
    cin >> n;
    for(int i=0; i<n; i++) {
        string dict;
        cin >> dict;
        insert(dict, root);
    }

    vector<int> dp(s.size()+1, 0);
    dp[s.size()] = 1;
    for(int i=s.size()-1; i>=0; i--){
        dp[i] = countWays(i, s, root, dp);
    }

    cout << dp[0] << "\n";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen("io/input.txt", "r", stdin);
    // freopen("io/output.txt", "w", stdout);

    solve();

    return 0;
}