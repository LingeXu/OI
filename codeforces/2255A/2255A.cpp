#include <bits/stdc++.h>
using namespace std;
int t, n, k;
string s;
void solve() {
    cin >> n >> k >> s;
    vector<int> a(2 * n);
    int red_score = 0, blue_score = 0;
    for(int i = 0; i < 2 * n; i++) {
        if(s[i] == '0')
            continue;
        if(s[(i + 1) % (2 * n)] == '0')
            a[(i + 1) % (2 * n)] = 1;
        else    a[i] = 1;
    }
    for(int i = 0; i < 2 * n; i++) {
        if(a[i] == 0)   continue;
        if(i % 2 == 0)  blue_score++;
        else    red_score++;
    }
    cout << red_score << ' ' << blue_score << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--)  solve();
    return 0;
}