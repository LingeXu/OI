#include <bits/stdc++.h>
#define N 500050
typedef long long ll;
using namespace std;
int n, m;
ll ans = -1e18;
int p[N];
ll s[N];
deque<int> dq;
int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> p[i];
        s[i] = s[i - 1] + 1LL * p[i];
    }
    dq.push_back(0);
    for(int i = 1; i <= n; i++) {
        while(!dq.empty() && dq.front() < i - m)
            dq.pop_front();
        if(!dq.empty())
            ans = max(ans, s[i] - s[dq.front()]);
        while(!dq.empty() && s[i] <= s[dq.back()])
            dq.pop_back();
        dq.push_back(i);
    }
    cout << ans;
    return 0;
}