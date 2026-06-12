#include <bits/stdc++.h>
#define N 70
using namespace std;
int n, sum = 0, min_ans, max_ans, target;
int a[N];
bool used[N];
bool dfs(int start, int remain, int cnt) {

    //cout << "start = " << start << ", remain = " << remain << ", cnt = " << cnt << '\n';

    if(cnt == sum / target)
        return true;
    if(remain == 0) {
        if(++cnt == sum / target)
            return true;
        for(int i = 0; i < n; i++) {
            if(!used[i]) {
                if(dfs(i, target, cnt))
                    return true;
                return false;
            }
        }
    }
    for(int i = start; i < n; i++) {
        if(!used[i] && a[i] <= remain) {
            used[i] = true;
            if(dfs(i + 1, remain - a[i], cnt))
                return true;
            used[i] = false;
            if(remain == target)
                return false;
            if(remain == a[i])
                return false;
            while(i + 1 < n && a[i + 1] == a[i])
                i++;     
        }
    }
    return false;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    sort(a, a + n, greater<int>());
    min_ans = a[0];
    max_ans = sum / 2;
    for(int i = min_ans; i <= max_ans; i++) {
        if(sum % i != 0)
            continue;
        memset(used, 0, sizeof(used));
        target = i;
        if(dfs(0, target, 0)) {
            cout << target;
            return 0;
        }
    }
    cout << sum;
}