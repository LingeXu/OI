#include <bits/stdc++.h>
#define N 55
using namespace std;
string s;
int f[N][N];
int dfs(int l, int r) {
    if(f[l][r] != -1)
        return f[l][r];
    if(l == r)
        return f[l][r] = 1;
    int ans = r - l + 1;
    if(s[l] == s[r])
        ans = min(dfs(l + 1, r), dfs(l, r - 1));
    else
        for(int k = l; k < r; k++)
            ans = min(ans, dfs(l, k) + dfs(k + 1, r));
    return f[l][r] = ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> s;
    memset(f, -1, sizeof(f));
    cout << dfs(0, s.size() - 1);
    return 0;    
}