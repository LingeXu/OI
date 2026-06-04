#include <bits/stdc++.h>
#define N 50050
typedef long long ll;
using namespace std;
int n;
int cnt[N];
struct cows {
    ll x, type;
    int new_type;
}c[N];
bool cmp1(cows a, cows b) {
    return a.x < b.x;
}
bool cmp2(cows a, cows b) {
    return a.type < b.type;
}
set<int> s;
int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> c[i].x >> c[i].type;
        s.insert(c[i].type);
    }
    int tot = s.size();
    sort(c + 1, c + n + 1, cmp2);
    int id = 0;
    for(int i = 1; i <= n; i++) {
        if(i == 1 || c[i].type != c[i - 1].type)
            c[i].new_type = ++id;
        else    c[i].new_type = id;
    }
    sort(c + 1, c + n + 1, cmp1);
    int j = 1;
    int varieties = 0;
    ll ans = 1e12;
    for(int i = 1; i <= n; i++) {
        while(varieties < tot && j <= n) {
            if(++cnt[c[j].new_type] == 1)
                varieties++;
            j++;
        }
        if(varieties == tot) {
            ans = min(ans, c[j - 1].x - c[i].x);
            if(--cnt[c[i].new_type] == 0)
                varieties--;
        }
        else    break;
    }
    cout << ans;
    return 0;
}