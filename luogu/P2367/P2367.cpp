#include <bits/stdc++.h>
#define N 5000050
#define INF 0x3f3f3f3f
using namespace std;
int n, p;
int a[N], d[N];
int main() {
    cin >> n >> p;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        d[i] = a[i] - a[i - 1];
    }
    for(int i = 1; i <= p; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        d[x] += z;
        d[y + 1] -= z;
    }
    int min_score = INF;
    for(int i = 1; i <= n; i++) {
        a[i] = a[i - 1] + d[i];
        min_score = min(min_score, a[i]);
    }
    cout << min_score;
    return 0;
}