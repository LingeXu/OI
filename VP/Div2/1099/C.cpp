#include <bits/stdc++.h>
using namespace std;
int t, n;
void solve() {
    cin >> n;
    priority_queue<int> pq;
    int sum = 0, mn = 0x3f3f3f3f, cnt_mn = 0;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if(x < mn) {
            mn = x;
            cnt_mn = 1;
        }
        else if(x == mn)    cnt_mn++;
        sum += x;
        pq.push(x);
    }
    int cnt = 0, tmp = 0x3f3f3f3f;
    while(sum != pq.top() * n) {
        int x = pq.top();
        pq.pop();
        if(x & 1) {
            pq.push(x + 1);
            sum++;
            cnt++;
        }
        else {
            if(x - mn == 1) {
                tmp = min(tmp, cnt + cnt_mn);
            }
            pq.push(x / 2);
            sum -= x / 2;
            cnt++;
            if(mn > x / 2) {
                mn = x / 2;
                cnt_mn = 1;
            }
            else if(mn == x / 2) {
                cnt_mn++;
            }
        }
    }
    cout << min(cnt, tmp) << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--)  solve();
    return 0;
}