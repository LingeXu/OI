#include <bits/stdc++.h>
using namespace std;
bool cmp(int x, int y) {
    return x > y;
}
int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(m + 1);
    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        a[x]++;
    }
    sort(a.begin(), a.end(), cmp);
    int mx = a[0], ans = 0;
    for(int i = 0; i < (int)a.size(); i++)
        if(a[i] == mx || a[i] == mx - 1 && a[i] != 0)
            ans++;
    cout << ans;
    return 0;
}