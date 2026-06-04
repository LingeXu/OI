#include <bits/stdc++.h>
#define N 100010
typedef long long ll;
using namespace std;
int n;
ll a[N], cp[N];
bool vis[N];
map< ll, pair<int, int> > mp;
;int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        cp[i] = a[i];
    }
    sort(cp + 1, cp + n + 1);
    for(int i = 1; i <= n; i++) {
        if(i == 1 || cp[i] != cp[i - 1]) {
            mp[cp[i]] = {i, i};
            continue;
        }
        int start = i;
        while(i <= n && cp[i] == cp[i - 1])
            i++;
        int end = i - 1;
        mp[cp[start]] = {start, end};
        i = end;
    }
    for(int i = 1; i <= n; i++) 
        a[i] = mp[a[i]].first++;
    int ans = 0, cnt = 0;
    for(int i = 1; i <= n; i++) {
        if(a[i] > i)    cnt++;
        if(vis[i])  cnt--;
        vis[a[i]] = true;
        ans = max(ans, cnt);
    }
    cout << ans;
    return 0;
}