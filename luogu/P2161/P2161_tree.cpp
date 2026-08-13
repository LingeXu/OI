#include <bits/stdc++.h>
#define N 200020
using namespace std;
int n, sum = 0;
int tree[N], endpos[N];
inline int lowbit(int x) {
    return x & (-x);
}
void add(int pos, int delta) {
    for(int  i = pos; i <= N; i += lowbit(i))   tree[i] += delta;
} 
int query(int pos) {
    int res = 0;
    for(int i = pos; i; i -= lowbit(i)) res += tree[i];
    return res;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    while(n--) {
        char c;
        cin >> c;
        if(c == 'A') {
            int l, r;
            cin >> l >> r;
            int del_cnt = 0;
            while(true) {
                int cnt = query(r);
                int Left = 1, Right = r, ans = -1;
                while(Left <= Right) {
                    int mid = Left + (Right - Left)/ 2;
                    if(query(mid) < cnt) 
                        Left = mid + 1;
                    else {
                        ans = mid;
                        Right = mid - 1;
                    }
                }
                if(endpos[ans] >= l) {
                    endpos[ans] = 0;
                    del_cnt++;
                    sum--;
                    add(ans, -1);
                }
                else    break;
            }
            add(l, 1);
            endpos[l] = r;
            sum++;
            cout << del_cnt << '\n';
        }
        else    cout << sum << '\n';
    }
    return 0;
}