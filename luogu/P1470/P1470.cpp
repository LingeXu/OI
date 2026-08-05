#include <bits/stdc++.h>
#define P 2020
#define S 200020
#define MAXC 26
using namespace std;
int trie_node_cnt = 1, ans = 0, repeat = 0;
string s, ob;
int trie[P][MAXC], end_cnt[P], sum_cnt[P], fail[P], depth[P];
bool dp[S];
set<string> pat;
void init() {
    trie_node_cnt = 1;
    memset(trie, 0, sizeof(trie));
    memset(end_cnt, 0, sizeof(end_cnt));
    memset(sum_cnt, 0, sizeof(sum_cnt));
    for(int i = 0; i < MAXC; i++)
        trie[0][i] = 1;
}
void insert(const string& word) {
    int current = 1;
    for(char c : word) {
        int idx = c - 'A';
        if(!trie[current][idx]) 
            trie[current][idx] = ++trie_node_cnt;
        current = trie[current][idx];
    }
    end_cnt[current]++;
    depth[current] = word.size();
}
void build() {
    queue<int> q;
    q.push(1);
    fail[1] = 0;
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(int i = 0; i < MAXC; i++) {
            if(trie[u][i]) {
                fail[trie[u][i]] = trie[fail[u]][i];
                q.push(trie[u][i]);
            }
            else    trie[u][i] = trie[fail[u]][i];
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    while(cin >> s && s != ".") 
        pat.insert(s);
    cin >> ob;
    init();
    for(string word : pat)    insert(word);
    build();
    dp[0] = true;
    int u = 1;
    for(int i = 0; i < ob.size(); i++) {
        int idx = ob[i] - 'A';
        u = trie[u][idx];
        int t = u;
        while(t != 0) {
            if(depth[t]) {
                if(i - depth[t] >= 0 && dp[i + 1 - depth[t]]) {
                    dp[i + 1] = true;
                    ans = max(ans, i + 1);
                    break;
                }
            }
            t = fail[t];
        }
    }
    cout << ans;
    return 0;
}