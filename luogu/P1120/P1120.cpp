#include <bits/stdc++.h>
#define N 66
#define SUM 65 * 30 + 1
using namespace std;
int n, sum = 0, max_length = 0;
int a[N];
bool used[N];

/*
bool check(int pos, int remain) {
    if(remain < 0)
        return false;
    if(remain == 0 && pos <= n)
        return true;
    if(pos == n && remain > 0)
        return false;
    if(used[pos]) {
        return check(pos + 1, remain);
    }
    else {
        bool use, notuse;
        used[pos] = true;
        use = check(pos + 1, remain - a[pos]);
        used[pos] = false;
        notuse = check(pos + 1, remain);
        return use || notuse;
    }
}*/

bool found = false;
void check(int x, int pos, int remain, int cnt) {
    for(int i = 0; i < n; i++)
        cout << used[i] << ' ';
    cout << '\n';
    cout << "pos = " << pos << ", remain = " << remain << ", cnt = " << cnt << '\n';
    if(found)
        return;
    if(pos == n && remain == x && cnt == sum / x) {
        found = true;
        return;
    }
    if(remain == 0) {
        int start;
        for(int i = 0; i < n; i++) {
            if(!used[i]) {
                start = i;
                break;
            }
        }
        cout << "start = " << start << '\n';
        check(x, start, x, cnt + 1);
        return;
    }
    if(pos == n + 1)
        return;
    if(remain < 0)
        return;
    if(cnt > sum % x)
        return;
    if(pos == n - 1 && (remain != a[n - 1] || cnt != sum / x - 1 || used[n - 1]))
        return;
    if(used[pos]) {
        check(x, pos + 1, remain, cnt);
        return;
    }
    else {
        used[pos] = true;
        check(x, pos + 1, remain - a[pos], cnt);
        used[pos] = false;
        check(x, pos + 1, remain, cnt);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
        max_length = max(max_length, a[i]);
    }

    /*check(sum, 0, sum, 0);
    cout << found << '\n';*/

    memset(used, 0, sizeof(used));
    check(6, 0, 6, 0);
    
    /*for(int i = max_length; i <= sum; i++) {
        if(sum % i == 0) {
            check(i, 0, i, 0);
            if(found) {
                cout << i;
                return 0;
            }
        }
    }*/
}