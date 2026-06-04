#include <bits/stdc++.h>
const int MAXB = (1 << 31);
using namespace std;
int n, cnt = 0;
int d[MAXB], ans[MAXB];
priority_queue<int, vector<int>, greater<int> > pq;
int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int a, b;
        cin >> a >> b;
        pq.push(b);
        d[a]++;
        d[b]--;
    }
    int Length = pq.top();
    for(int i = 1; i <= Length; i++) {
        ans[i] = ans[i - 1] + d[i];
        if(ans[i] != 0)
            cnt++;
    }
    cout << cnt;
    return 0;
}