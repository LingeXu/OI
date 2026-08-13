#include <bits/stdc++.h>
#define N 200020
typedef long long ll;
using namespace std;
int t, n;
int cnt1 = 0, cnt2 = 0;
ll m;
ll a[2 * N], b[2 * N];
void solve() {
    cnt1 = cnt2 = 0;
    cin >> n >> m;
    for(int i = 0; i < 2 * n; i++) {
        cin >> a[i];
        b[i] = a[i];
    }
    a[0] += m;
    if(a[1] > a[0]) cnt1++;
    for(int i = 1; i <= n - 1; i++) {
        if(a[2 * i] > a[0] && a[2 * i + 1] > a[0])    cnt1 += 2;
        else if(a[2 * i] > a[0] && a[2 * i + 1] <= a[0])    cnt1 += 1;
        else if(a[2 * i] <= a[0] && a[2 * i + 1] > a[0])    cnt1 += 1;
        else {
            if(2 * a[0] - a[2 * i] - a[2 * i + 1] >= m)    continue;
            else    cnt1 += 1;
        }
    }
    b[1] += m;
    if(b[1] > b[0]) cnt2++;
    for(int i = 1; i <= n - 1; i++) {
        if(b[2 * i] > b[0] && b[2 * i + 1] > b[0])    cnt2 += 2;
        else if(b[2 * i] > b[0] && b[2 * i + 1] <= b[0]) {
            if(b[0] - b[2 * i + 1] < m)    cnt2 += 2;
            else    cnt2 += 1;
        }
        else if(b[2 * i] <= b[0] && b[2 * i + 1] > b[0]) {  
            if(b[0] - b[2 * i] < m)    cnt2 += 2;
            else    cnt2 += 1;
        }
        else {
            int d1 = b[0] - b[2 * i], d2 = b[0] - b[2 * i + 1];
            if(d1 >= m && d2 >= m)    continue;
            else if(m > d1 && d2 >= m)    cnt2 += 1;
            else if(d1 >= m && m > d2)    cnt2 += 1;
            else {
                if(m > d1 + d2)    cnt2 += 2;
                else    cnt2 += 1;
            }
        }
    }
    cout << cnt1 << ' ' << cnt2 << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--)    solve();
    return 0;
}