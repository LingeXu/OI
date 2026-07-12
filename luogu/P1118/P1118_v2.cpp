#include <bits/stdc++.h>
#define N 13
using namespace std;
int n, sum;
int yh[N][N];
bool occupied[N];
vector<int> ans;
bool dfs(int pos, int now) {
    if(now > sum)   return false;
    if(pos == n + 1)    return now == sum;
    for(int i = 1; i <= n; i++) {
        if(!occupied[i]) {
            occupied[i] = true;
            if(dfs(pos + 1, now + yh[n][pos] * i)) {
                ans.push_back(i);
                return true;
            }
            occupied[i] = false;
        }
    }
    return false;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> sum;
    for(int i = 1; i <= n; i++)
        yh[i][1] = yh[i][i] = 1;
    for(int i = 3; i <= n; i++)
        for(int j = 2; j < i; j++)
            yh[i][j] = yh[i - 1][j - 1] + yh[i - 1][j];
    if(dfs(1, 0))
        for(int i = ans.size() - 1; i >= 0; i--)
            cout << ans[i] << ' ';
    return 0;
}