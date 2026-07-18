#include <bits/stdc++.h>
using namespace std;
string a, b;
int dfs(int l1, int l2, int r1, int r2) {
    bool need_change = false;
    if(r1 - l1 != r2 - l2)
        need_change = true;
    if(!need_change) {
        for(int i = l1, j = l2; i <= r1 && j <= r2; i++, j++) {
            if(a[i] != b[j]) {
                need_change = true;
                break;
            }
        }
    }
    if(!need_change)
        return 0;
    int ans = max(r1 - l1 + 1, r2 - l2 + 1);
    for(int i = l1; i < r1; i++)
        for(int j = l2; j < r2; j++)
            ans = min(ans, dfs(l1, l2, i, j) + dfs(i + 1, j + 1, r1, r2));
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> a >> b;
    cout << dfs(0, 0, a.size() - 1, b.size() - 1);
    return 0;
}