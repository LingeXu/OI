#include <bits/stdc++.h>
#define N 505
#define M 505
typedef unsigned long long ull;
const int BASE = 13331;
using namespace std;

int n, m, k, cnt = 0;
int a[N][M];
ull p[N], hashval[N][M];
bool suspicious[M][M];
unordered_map <ull, unordered_set<int>> mp;

void prehash() {
    p[0] = 1;
    for(int i = 1; i <= n; i++)
        p[i] = p[i - 1] * BASE;
    for(int col = 0; col < m; col++) {
        hashval[0][col] = 0;
        for(int row = 1; row < n; row++) {
            ull val = (ull)(a[row][col] - a[row - 1][col] + 100000);
            hashval[row][col] = hashval[row - 1][col] * BASE + val;
        }
    }
}
ull gethash(int col_idx, int start, int length) {
    if(length == 0) return 0;  
    int l = start + 1;
    int r = start + length;
    return hashval[r][col_idx] - hashval[l - 1][col_idx] * p[length];
}
void deal(int col_idx) {
    int length = k - 1;
    for(int start = 0; start + length - 1 < n - 1; start++) {
        ull val = gethash(col_idx, start, length);
        mp[val].insert(col_idx);
    }
}
void stat() {
    for(auto& entry : mp) {
        unordered_set<int>& cols = entry.second;
        if(cols.size() < 2) continue;
        vector<int> col_idx_list(cols.begin(), cols.end());
        sort(col_idx_list.begin(), col_idx_list.end());
        for(int i = 0; i < (int)col_idx_list.size(); i++) 
            for(int j = i + 1; j < (int)col_idx_list.size(); j++) 
                suspicious[col_idx_list[i]][col_idx_list[j]] = true;

    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k;
    if(k == 1) {
        cout << 1LL * m * (m - 1) / 2 << '\n';
        return 0;
    }
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> a[i][j];
    prehash();
    for(int i = 0; i < m; i++)
        deal(i);
    stat();
    for(int i = 0; i < m; i++)
        for(int j = i + 1; j < m; j++)
            cnt += suspicious[i][j];
    cout << cnt;
    return 0;
}