/*#include <bits/stdc++.h>
using namespace std;
int t, n;
bool cmp(int x, int y) {
    return x > y;
}
void solve() {
    cin >> n;
    vector<int> a(n);
    unordered_map<int, int> remain;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        remain[a[i]]++;
    }
    sort(a.begin(), a.end(), cmp);
    a.erase(unique(a.begin(), a.end()), a.end());
    int m = (int)a.size();

    //cout << "m = " << m << '\n';

    for(int i = 0; i < m; i++) {
        int cur = remain[a[i]];
        if(cur <= 0)    continue;
        for(int j = i; j < m; j++) {
            if(remain[a[j]] <= 0)   continue;
            for(int k = 1; k <= min(cur, remain[a[j]]); k++) 
                cout << a[j] << ' ';
            remain[a[j]] -=  min(cur, remain[a[j]]);
        }
    }
    cout << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while(t--)  solve();
    return 0;
}*/

#include <bits/stdc++.h>
using namespace std;
int t, n;
bool cmp(int x, int y) {
    return x > y;
}
void solve() {
    cin >> n;
    vector<int> a(n);
    unordered_map<int, int> mp;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        mp[a[i]]++;
    }
    sort(a.begin(), a.end(), cmp);
    a.erase(unique(a.begin(), a.end()), a.end());
    int m = (int)a.size();
    for(int i = 0; i < m; i++) {
        if(mp[a[i]] <= 0)   continue;
        int cur = mp[a[i]];
        for(int j = 1; j <= cur; j++)
            cout << a[i] << ' ';
        for(int j = i + 1; j < m; j++) {
            if(mp[a[j]] <= 0)   continue;
            for(int k = 1; k <= min(cur, mp[a[j]]); k++)
                cout << a[j] << ' ';
            mp[a[j]] -= min(cur, mp[a[j]]);
        }
    }
    cout << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--)  solve();
    return 0;
}