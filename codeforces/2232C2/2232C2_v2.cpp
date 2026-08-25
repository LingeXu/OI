#include <bits/stdc++.h>
#define int long long
using namespace std;
int t, n, x, s;
string q;
int eval(const string& q, int mid) {
    int res = 0, empty = x;
    for(char c : q) {
        if(c == 'E') {
            if(res < (x - empty) * s)   res++;
        }
        else if(c == 'I') {
            if(empty > 0) {
                empty--;
                res++;
            }
        }
        else {
            if(mid > 0){
                if(empty > 0) {
                    empty--;
                    res++;
                }
                mid--;
            }
            else
                if(res < (x - empty) * s)   res++;
        }
    }
    return res;
}
void solve() {
    cin >> n >> x >> s >> q;
    int A_cnt = 0;
    for(char c : q)
        if(c == 'A')
            A_cnt++;
    int l = 0, r = A_cnt;
    while(l < r) {
        int mid = l + (r - l) / 2;
        int x = eval(q, mid), y = eval(q, mid + 1);
        if(x >= y)  r = mid;
        else    l = mid + 1;
    }
    cout << eval(q, l) << '\n';
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while(t--)  solve();
    return 0;
}