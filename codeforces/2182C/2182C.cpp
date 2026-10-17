#include <bits/stdc++.h>
using namespace std;
#define int long long
int t, n;
void solve() {
    cin >> n;
    vector<int> a(n), b(n), c(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 0; i < n; i++)
        cin >> b[i];
    for(int i = 0; i < n; i++)
        cin >> c[i];
    vector<int> ans1;
    for(int i = 0; i < n; i++) {
        if(a[0] >= b[i])    continue;
        bool ok = true;
        for(int j = 1; j < n; j++) {
            if(a[j] >= b[(i + j) % n]) {
                ok = false;
                break;
            }
        }
        if(!ok)
            continue;
        ans1.push_back(i);
    }
    vector<int> ans2;
    for(int i = 0; i < n; i++) {
        if(b[0] >= c[i])    continue;
        bool ok = true;
        for(int j = 1; j < n; j++) {
            if(b[j] >= c[(i + j) % n]) {
                ok = false;
                break;
            }
        }
        if(!ok)
            continue;
        ans2.push_back(i);
    }
    /*vector<int> ans3(n, 0);
    for(int i = 0; i < n; i++) {
        if(a[0] >= c[i])    continue;
        bool ok = true;
        for(int j = 1; j < n; j++) {
            if(a[j] >= c[(i + j) % n]) {
                ok = false;
                break;
            }
        }
        if(!ok)
            continue;
        ans3[i] = 1;
    }
    int cnt = 0;
    for(int i : ans1)
        for(int j : ans2)
            if(ans3[i + j] == 1)
                cnt++;
    cout << cnt << '\n';*/
    //cout << "ans1 = " << (int)ans1.size() << ", ans2 = " << (int)ans2.size() << '\n';
    cout << (int)ans1.size() * (int)ans2.size() * n << '\n';
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--)  solve();
    return 0;
}