#include <bits/stdc++.h>
#define M 1000010
#define N 1000010
typedef long long ll;
using namespace std;
int n, m;
ll  r[N], d[N], s[N], t[N], diff[N], sum[N];
bool check(int x) {
    memset(diff, 0, sizeof(diff));
    for(int i = 1; i <= x; i++) {
        diff[s[i]] += d[i];
        diff[t[i] + 1] -= d[i];
    }
    for(int i = 1; i <= n; i++) {
        sum[i] = sum[i - 1] + diff[i];
        if(sum[i] > r[i])   return false;
    }
    return true;
}
int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> r[i];
    for(int i = 1; i <= m; i++) 
        cin >> d[i] >> s[i] >> t[i];
    int Left = 1, Right = m;
    int ans = m;
    if(check(Right)) {
        cout << 0;
        return 0;
    }
    while(Left <= Right) {
        int Mid = Left + (Right - Left) / 2;
        if(check(Mid)) 
            Left = Mid + 1;
        else {
            ans = Mid;
            Right = Mid - 1;
        }
    }
    cout << -1 << '\n';
    cout << ans;
    return 0;
}