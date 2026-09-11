#include <bits/stdc++.h>
#define N 505
#define M 505
#define BASE 13331
typedef unsigned long long ull;
using namespace std;
int n, m, k, cnt = 0;
int a[N][M];
bool suspicious[M][M];
ull diff[N][M], p[N], hashval[N][M];
unordered_map< ull, unordered_set<int> > mp;
void prehash() {
    p[0] = 1;
    for(int i = 1; i <= n - 2; i++)
        p[i] = p[i - 1] * BASE;
    for(int col = 0; col < m; col++) {
        for(int row = 0; row <= n - 1; row++) {
            if(row == 0)
                hashval[row][col] = 0;
            else    hashval[row][col] = hashval[row - 1][col] * BASE + diff[row][col];
        }
    }
}
ull gethash(int col_idx, int start, int length) {
    return hashval[start + length][col_idx] - hashval[start][col_idx] * p[length];
}
void process() {
    int length = k - 1;
    for(int col = 0; col < m; col++) 
        for(int start = 0; start + length - 1 <= n - 2; start++) 
            mp[gethash(col, start, length)].insert(col);
}
void mark() {
    for(auto& entry : mp) {
        if(entry.second.size() < 2)
            continue;
        vector<int> col_idx(entry.second.begin(), entry.second.end());
        sort(col_idx.begin(), col_idx.end());
        for(int i = 0; i < col_idx.size(); i++)
            for(int j = i + 1; j < col_idx.size(); j++)
                suspicious[col_idx[i]][col_idx[j]] = true;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> a[i][j];
    if(k == 1) {
        cout << m * (m - 1) / 2;
        return 0;
    }
    for(int i = 1; i < n; i++)  
        for(int j = 0; j < m; j++)
            diff[i][j] = a[i][j] - a[i - 1][j] + 100000;
    prehash();
    process();
    mark();
    for(int i = 0; i < m; i++)
        for(int j = i + 1; j < m; j++)
            cnt += suspicious[i][j];
    cout << cnt;
    return 0;
}