#include <bits/stdc++.h>
using namespace std;
int t, ans;
vector<int> prefix1, prefix2;
string s1, s2;
int dfs(int l1, int r1, int l2, int r2) {
    if((prefix1[r1] + 10 - prefix1[l1 - 1]) % 10 != (prefix2[r2] + 10 - prefix2[l2 - 1]) % 10)
        return -0x3f3f3f3f;
    int res = 1;
    if(l1 == r1 && s1[l1 - 1] - '0' == (prefix2[r2] + 10 - prefix2[l2 - 1]) % 10)
        return 1;
    if(l2 == r2 && s2[l2 - 1] - '0' == (prefix1[r1] + 10 - prefix1[l1 - 1]) % 10)
        return 1;
    for(int i = l1; i < r1; i++)
        for(int j = l2; j < r2; j++)
            res = max(res, dfs(l1, i, l2, j) + dfs(i + 1, r1, j + 1, r2));
    return res;
}
void solve() {
    prefix1.clear();
    prefix2.clear();
    cin >> s1 >> s2;
    prefix1.push_back(0);
    for(int i = 0; i < (int)s1.size(); i++)     
        prefix1.push_back((prefix1.back() + s1[i] - '0') % 10);
    prefix2.push_back(0);
    for(int i = 0; i < (int)s2.size(); i++) 
        prefix2.push_back((prefix2.back() + s2[i] - '0') % 10);
    ans = dfs(1, (int)s1.size(), 1, (int)s2.size());
    cout << (ans > 0 ? ans : -1) << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    while(t--)  solve();
    return 0;
}