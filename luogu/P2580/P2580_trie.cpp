#include <bits/stdc++.h>
#define N 10010
using namespace std;
int n, m, trie_node_cnt = 0;
string s1, s2;
int trie[50 * N][26], end_cnt[50 * N];
bool is_end[50 * N];
void add(const string& s) {
    int cur = 0;
    for(char c : s) {
        int idx = c - 'a';
        if(!trie[cur][idx]) 
            trie[cur][idx] = ++trie_node_cnt;
        cur = trie[cur][idx];
    }
    is_end[cur] = true;
}
void query(const string& s) {
    int cur = 0;
    for(char c : s) {
        int idx = c - 'a';
        if(!trie[cur][idx]) {
            cout << "WRONG\n";
            return;
        }
        cur = trie[cur][idx];
    }
    if(is_end[cur] == false)    cout << "WRONG\n";
    else {
        if(++end_cnt[cur] == 1)
            cout << "OK\n";
        else    cout << "REPEAT\n";
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> s1;
        add(s1);
    }
    cin >> m;
    for(int i = 0; i < m; i++) {
        cin >> s2;
        query(s2);
    }
    return 0;
}