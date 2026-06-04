#include <bits/stdc++.h>
#define N 200020
#define INF 0x3f3f3f3f
using namespace std;
int n, l, r;
int a[N], max_ans[N];
deque<int> dq;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> l >> r;
    for(int i = 0; i <= n; i++)
        cin >> a[i];
    memset(max_ans, 0xcf, sizeof(max_ans));
    max_ans[0] = 0;
    for(int i = 0; i <= n; i++) {
        if(i >= l) {
            while(!dq.empty() && max_ans[dq.back()] <= max_ans[i - l])
                dq.pop_back();
            dq.push_back(i - l);
        }
        while(!dq.empty() && dq.front() < i - r)
            dq.pop_front();
        if(!dq.empty())
            max_ans[i] = max_ans[dq.front()] + a[i];
    }
    int ans = 0xcfcfcfcf;
    int start = max(0, n - r + 1);
    for(int i = start; i <= n; i++)
        ans = max(ans, max_ans[i]);
    cout << ans << endl;
    return 0;
}