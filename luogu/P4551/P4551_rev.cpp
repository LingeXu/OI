#include <bits/stdc++.h>
#define N 100010
#define MAX_BITS 30
using namespace std;
int n, trie_node_cnt = 0, max_xor = 0;
int trie[30 * N + 1][2];
bool vis[N];
vector< pair<int, int> > graph[N];
vector<int> dis_to_root;
void dfs(int u, int rev) {
    if(vis[u])  return;
    vis[u] = true;
    dis_to_root.push_back(rev);
    for(auto& e : graph[u]) 
        dfs(e.second, rev ^ e.first);
}
void init() {
    trie_node_cnt = 0;
    memset(trie, 0, sizeof(trie));
}
void build() {
    for(int num : dis_to_root) {
        int current = 0;
        for(int i = MAX_BITS; i >= 0; i--) {
            int idx = (num >> i) & 1;
            if(!trie[current][idx])
                trie[current][idx] = ++trie_node_cnt;
            current = trie[current][idx];
        }
    }
}
int query(int num) {
    int current = 0;
    for(int i = MAX_BITS; i >= 0; i--) {
        int want = ((num >> i) & 1) ^ 1;
        if(trie[current][want]) {
            current = trie[current][want];
            num = num | (1 << i);
        }
        else {
            current = trie[current][1 - want];
            num = num & (~(1 << i));
        }
    }
    return num;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({w, v});
        graph[v].push_back({w, u});
    }
    dfs(1, 0);
    build();
    for(int num : dis_to_root)
        max_xor = max(max_xor, query(num));
    cout << max_xor;
    return 0;
}