#include <bits/stdc++.h>
#define N 100010
typedef long long ll;
using namespace std;
int n, m;
int a[N];
ll sum[N];
int main() {
    cin >> n;
    sum[0] = 0;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        sum[i] = sum[i - 1] + (long long)a[i];
    }
    cin >> m;
    for(int i = 1; i <= m; i++) {
        int Left, Right;
        cin >> Left >> Right;
        cout << sum[Right] - sum[Left - 1] << '\n';
    }
    return 0;
}