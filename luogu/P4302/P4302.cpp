#include <bits/stdc++.h>
#define N 110
using namespace std;
string s;
int m[N], f[N][N];
bool check(int l, int r, int len) {
    if((r - l + 1) % len != 0)
        return false;
    for(int i = l + len; i <= r; i++)
        if(s[i] != s[l + (i - l) % len])
            return false;
    return true;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> s;
    for(int i = 1; i <= 100; i++) {
        if(i < 10)
            m[i] = 1;
        else if(i >= 10 && i < 100)
            m[i] = 2;
        else    m[i] = 3;
    }
    for(int i = 0; i < s.size(); i++)
        f[i][i] = 1;
    for(int len1 = 2; len1 <= s.size(); len1++) {
        for(int l = 0; l + len1 - 1 < s.size(); l++) {
            int r = l + len1 - 1, ans = len1;
            for(int len2 = 1; len2 < len1; len2++) 
                if(check(l, r, len2)) 
                    ans = min(ans, m[len1 / len2] + 2 + f[l][l + len2 - 1]);
            for(int k = l; k < r; k++)
                ans = min(ans, f[l][k] + f[k + 1][r]);
            f[l][r] = ans;
        }
    }
    cout << f[0][s.size() - 1];
    return 0;
}