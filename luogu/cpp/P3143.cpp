#include <bits/stdc++.h>
#define N 50050
using namespace std;
int n, k, ans = 0;
int a[N], R[N], suffix_max[N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    for(int i = 0; i < n; i++)  cin >> a[i];
    sort(a, a + n);
    int r_start = 0;
    for(int i = 0; i < n; i++) {
        while(r_start < n && a[r_start] - a[i] <= k)
            r_start++;
        R[i] = r_start - 1;
    }
    for(int i = n - 1; i >= 0; i--)
        suffix_max[i] = max(suffix_max[i + 1], R[i] - i + 1);
    for(int i = 0; i < n; i++) 
        ans = max(ans, R[i] - i + 1 + suffix_max[R[i] + 1]);
    cout << ans;
    return 0;
}