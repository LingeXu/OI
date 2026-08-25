#include <bits/stdc++.h>
#define N 2020
using namespace std;
int n, trie_node_cnt = 0, ans = 0;
int trie[10 * N][26], end_cnt[10 * N];
string s;
int add(const string& s) {
    int cur = 0, res = 0;
    for(char c : s) {
        int idx = c - 'a';
        if(!trie[cur][idx]) trie[cur][idx] = ++trie_node_cnt;
        cur = trie[cur][idx];
        res += end_cnt[cur];
    }
    end_cnt[cur]++;
    return res + 1;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> s;
        ans = max(ans, add(s));
    }
    cout << ans;
    return 0;
}