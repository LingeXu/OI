#include <bits/stdc++.h>
#define N 1010
typedef long long ll;
using namespace std;
int n;
struct square {
    int x1, y1, x2, y2;
}s[N];
bool cmp(square a, square b) {
    return a.x1 < b.x1 && a.y2 < b.y2;
}
int main() {
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> s[i].x1 >> s[i].y1 >> s[i].x2 >> s[i].y2;
    sort(s, s + n, cmp);
    ll ans = 0;
    for(int i = 0; i < n; i++) {
        ans += 1LL * (s[i].x2 - s[i].x1) * (s[i].y1 - s[i].y2);
        ll coincide_x, coincide_y;
        if(i != 0) {
            if(s[i].x2 <= s[i - 1].x2)
                coincide_x = 1LL * (s[i].x2 - s[i].x1);
            else if(s[i].x1 < s[i - 1].x2 && s[i].x2 > s[i - 1].x2)
                coincide_x = 1LL * (s[i - 1].x2 - s[i].x1);
            else if(s[i].x1 >= s[i - 1].x2)
                coincide_x = 0;
            if(s[i].y1 <= s[i - 1].y1)
                coincide_y = 1LL * (s[i].y1 - s[i].y2);
            else if(s[i].y2 < s[i - 1].y1 && s[i].y1 > s[i - 1].y1)
                coincide_y = 1LL * (s[i - 1].y1 - s[i].y2);
            else if(s[i].y2 >= s[i - 1].y1)
                coincide_y = 0;
            ans -= coincide_x * coincide_y;
        }
    }
    cout << ans;
    return 0;
}