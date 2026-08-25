#include <bits/stdc++.h>
#define N 2200
#define MAXC 26
#define S 200020
using namespace std;
int trie_node_cnt = 1, ans = 0;
string s1, s2;
int trie[N][MAXC], depth[N], fail[N];
bool is_end[N], dp[S];
void init() {
    memset(trie, 0, sizeof(trie));  
    memset(depth, 0, sizeof(depth));
    memset(fail, 0, sizeof(fail));
    memset(is_end, 0, sizeof(is_end));
    memset(dp, 0, sizeof(dp));
    for(int i = 0; i < MAXC; i++)
        trie[0][i] = 1;
}
void Insert(const string& s) {
    int cur = 1;
    for(char c : s) {
        int idx = c - 'A';
        if(!trie[cur][idx]) 
            trie[cur][idx] = ++trie_node_cnt;
        cur = trie[cur][idx];
    }
    is_end[cur] = true;
    depth[cur] = (int)s.size();
}
void build() {
    queue<int> q;
    q.push(1);
    while(!q.empty()) {
        int x = q.front();
        q.pop();
        for(int i = 0; i < MAXC; i++) {
            if(trie[x][i]) {
                fail[trie[x][i]] = trie[fail[x]][i];
                q.push(trie[x][i]);
            }
            else    trie[x][i] = trie[fail[x]][i];
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    init();
    while(cin >> s1 && s1 != ".") 
        Insert(s1);
    build();
    string line;
    while(cin >> line)
        s2 += line;
    int cur = 1;
    dp[0] = true;
    for(int i = 0; i < (int)s2.size(); i++) {
        int idx = s2[i] - 'A';
        cur = trie[cur][idx];
        int u = cur;
        while(u != 0) {
            if(depth[u] && i + 1 - depth[u] >= 0 && dp[i + 1 - depth[u]]) {
                dp[i + 1] = true;
                ans = max(ans, i + 1);
                break;
            }
            u = fail[u];
        }
    }
    cout << ans;
    return 0;
}