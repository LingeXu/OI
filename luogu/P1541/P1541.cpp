#include <bits/stdc++.h>
#define N 355
#define M 130
using namespace std;
int n, m;
int remain1 = 0;
int remain2 = 0;
int remain3 = 0;
int remain4 = 0;
int a[N], b[M];
int dfs(int current_score, int pos, int remain1, int remain2, int remain3, int remain4) {
    if(pos == n)
        return current_score;
    int res = 0;
    if(remain1 > 0)
        res = max(res, dfs(current_score + a[pos + 1], pos + 1, remain1 - 1, remain2, remain3, remain4));
    if(remain2 > 0)
        res = max(res, dfs(current_score + a[pos + 2], pos + 2, remain1, remain2 - 1, remain3, remain4));
    if(remain3 > 0)
        res = max(res, dfs(current_score + a[pos + 3], pos + 3, remain1, remain2, remain3 - 1, remain4));
    if(remain4 > 0)
        res = max(res, dfs(current_score + a[pos + 4], pos + 4, remain1, remain2, remain3, remain4 - 1));
    return res;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i = 1; i <= m; i++) {
        cin >> b[i];
        if(b[i] == 1)
            remain1++;
        else if(b[i] == 2)
            remain2++;
        else if(b[i] == 3)
            remain3++;
        else    remain4++;
    }
    cout << a[1] + dfs(0, 1, remain1, remain2, remain3, remain4);
    return 0;
}