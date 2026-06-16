#include <bits/stdc++.h>
using namespace std;


// <<==================================== Trees ====================================>> //


// ----------------- Trie Data Structure (Prefix Tree) ----------------- //

class Node{
    vector<Node*> nodes;
    bool end;

    public:
    Node(){ nodes.resize(26, nullptr); }

    bool containsKey(char c){
        return nodes[c-'a'] != nullptr;
    }
    void put(char c, Node* a){
        nodes[c-'a'] = a;
    }
    Node* getKey(char c){
        return nodes[c-'a'];
    }
    void setEnd(){
        end = true;
    }
    bool isEnd(){
        return end;
    }
};

class Trie{
    Node* root;
    
    public:
    Trie(){ root = new Node(); }
    
    void insert(string& s){
        Node* temp = root;
        for(auto c: s){
            if(!temp->containsKey(c)){
                temp->put(c, new Node());
            }
            temp = temp->getKey(c);
        }
        temp->setEnd();
    }

    int longestPrefix(string& s){
        Node* temp = root;
        int len = 0;
        for(auto c: s){
            if(!temp->containsKey(c)) break;
            len++;
            temp = temp->getKey(c);
        }
        return len;
    }

    bool wordExist(string& s){
        Node* temp = root;
        for(auto c: s){
            if(!temp->containsKey(c)) return false;
            temp = temp->getKey(c);
        }
        return temp->isEnd();
    }
};


// <<==================================== Range Queries ====================================>> //


// ----------------- Segment Tree (SegTree) ----------------- //

class SegmentTree{

    vector<int> seg, update;

    public:
    SegmentTree(vector<int>& nums){
        int n = nums.size();
        seg.resize(4*n+5, 0);
        update.resize(4*n+5, 0);
        buildTree(0, n-1, 0, nums);
    }

    void buildTree(int lo, int hi, int node, vector<int>& nums){
        if(lo == hi){
            seg[node] = nums[lo];
            return;
        }
        int mid = lo + (hi - lo) / 2;
        buildTree(lo, mid, 2*node+1, nums);
        buildTree(mid+1, hi, 2*node+2, nums);
        seg[node] = seg[2*node+1] + seg[2*node+2];
    }

    void pointUpdate(int lo, int hi, int node, int index, int del){
        if(lo == hi){
            seg[node] += del;
            return;
        }

        int mid = lo + (hi - lo) / 2;
        if(index <= mid) pointUpdate(lo, mid, 2*node+1, index, del);
        else pointUpdate(mid+1, hi, 2*node+2, index, del);
        seg[node] = seg[2*node+1] + seg[2*node+2];
    }

    void push(int lo, int hi, int node){
        if(update[node] != 0){
            seg[node] += (hi - lo + 1) * update[node];
            if(lo != hi){
                update[2*node+1] += update[node];
                update[2*node+2] += update[node];
            }
            update[node] = 0;
        }
    }

    void lazyUpdate(int lo, int hi, int node, int l, int r, int del){

        push(lo, hi, node); // Push Upate

        if(hi < l || r < lo) return; // Not in range

        if(l <= lo && hi <= r){ // Lie between range
            seg[node] += (hi - lo + 1) * del;
            if(lo != hi){
                update[2*node+1] += del;
                update[2*node+2] += del;
            }
            return;
        }

        int mid = lo + (hi - lo) / 2;
        lazyUpdate(lo, mid, 2*node+1, l, r, del);
        lazyUpdate(mid+1, hi, 2*node+2, l, r, del);
        seg[node] = seg[2*node+1] + seg[2*node+2];
    }

    int querySum(int lo, int hi, int node, int l, int r){

        push(lo, hi, node); // Push Upate

        if(hi < l || r < lo) return 0; // Not in range

        if(l <= lo && hi <= r) return seg[node]; // Lie between range

        int mid = lo + (hi - lo) / 2;
        int leftSum = querySum(lo, mid, 2*node+1, l, r);
        int rightSum = querySum(mid+1, hi, 2*node+2, l, r);

        return leftSum + rightSum;
    }
};


// ----------------- Binary Indexed Tree (BIT) ----------------- //

class FenWickTree{};


// ----------------- Sparse Table (ST) ----------------- //

class SparseTable{};


// ----------------- Least Common Ancestor (LCA) ----------------- //

class LCA{};


// <<==================================== Graphs ====================================>> //


// ----------------- Depth First Search (DFS) ----------------- //

void dfs(int node, vector<int>& vis, vector<vector<int>>& adj){
    vis[node] = 1;
    for(auto nei: adj[node]){
        if(vis[nei]) continue;
        dfs(nei, vis, adj);
    }
}


// ----------------- Breadth First Search (BFS) ----------------- //

void bfs(int n, int src=0, vector<vector<int>>& adj){
    vector<int> vis(n);

    queue<int> q;
    q.push(src);
    vis[src] = 1;
    while(!q.empty()){
        int node = q.front(); q.pop();
        for(auto nei: adj[node]){
            if(vis[nei]) continue;
            vis[nei] = 1;
            q.push(nei);
        }
    }
}


// ----------------- Dijkstra Algorithm ----------------- //

int INF = (int)1e9;
vector<int> dijkstra(int n, vector<vector<int>>& edges){

    vector<vector<pair<int, int>>> adj(n);
    for(auto e: edges){
        adj[e[0]].push_back({e[1], e[2]});
        adj[e[1]].push_back({e[0], e[2]});
    }

    vector<int> dist(n, INF);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 0});
    while(!pq.empty()){
        auto [cost, node] = pq.top(); pq.pop();
        if(cost > dist[node]) continue;
        for(auto [adjNode, edgW]: adj[node]){
            if(dist[adjNode] > cost + edgW){
                dist[adjNode] = cost + edgW;
                pq.push({dist[adjNode], adjNode});
            }
        }
    }

    return dist;
}


// ----------------- Disjoint Set Union (DSU) ----------------- //

class DisjointSet{

    vector<int> parent, size;

    public:
    DisjointSet(int n){
        parent.resize(n+1, 0);
        size.resize(n+1, 1);
        for(int i=0; i<=n; i++) parent[i] = i;
    }

    int findParent(int node){
        if(parent[node] == node) return node;
        return parent[node] = findParent(parent[node]);
    }

    void unionBySize(int u, int v){
        int ulp_u = findParent(u);
        int ulp_v = findParent(v);

        if(size[ulp_u] >= size[ulp_v]){
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
        else{
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
    }

};
