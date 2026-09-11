#include <bits/stdc++.h>
#define N 200020
using namespace std;
int n, ans, min_prefix = 0;
int a[N], prefix[N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    ans = 2 * n - 1;
    for(int i = 1; i <= 2 * n; i++) {
        cin >> a[i];
        prefix[i] = prefix[i - 1] + (a[i] == 1 ? 1 : -1);
        if(prefix[i] < min_prefix) {
            min_prefix = prefix[i];
            ans = i - 1;
        }
    }
    cout << ans;
    return 0;
}