#include <bits/stdc++.h>
#define N 100010
const int MOD = 1e8 - 3;
using namespace std;
int n, ans = 0;
int true_a[N], true_b[N], reflect[N], tmp[N];
struct node {
    int val, id, rk;
}a[N], b[N];
bool cmp(node x, node y) {
    return x.val < y.val;
}
int merge(int l, int mid, int r) {
    int i = l, j = mid + 1;
    int cnt = 0, k = 1;
    while(i <= mid && j <= r) {
        if(true_b[i] > true_b[j]) {
            cnt = (cnt + mid - i + 1) % MOD;
            tmp[k++] = true_b[j++];
        }
        else    tmp[k++] = true_b[i++];
    }
    while(i <= mid)
        tmp[k++] = true_b[i++];
    while(j <= r)
        tmp[k++] = true_b[j++];
    for(int i = l; i <= r; i++)
        true_b[i] = tmp[i - l + 1];
    return cnt;
}
int merge_sort(int l, int r) {
    if(l >= r)  return 0;
    int mid = l + (r - l) / 2;
    return merge_sort(l, mid) + merge_sort(mid + 1, r) + merge(l, mid, r);
}
int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i].val;
        a[i].id = i;
    }
    sort(a + 1, a + n + 1, cmp);
    for(int i = 1; i <= n; i++)
        a[i].rk = i;
    for(int i = 1; i <= n; i++)
        true_a[a[i].id] = a[i].rk;
    for(int i = 1; i <= n; i++) {
        cin >> b[i].val;
        b[i].id = i;
    }
    sort(b + 1, b + n + 1, cmp);
    for(int i = 1; i <= n; i++)
        b[i].rk = i;
    for(int i = 1; i <= n; i++)
        true_b[b[i].id] = b[i].rk;

    /*for(int i = 1; i <= n; i++)
        cout << true_a[i] << ' ' << true_b[i] << '\n';*/

    for(int i = 1; i <= n; i++) {
        reflect[true_a[i]] = i;
        true_a[i] = i;
    }
    for(int i = 1; i <= n; i++)
        true_b[i] = reflect[true_b[i]];
    cout << merge_sort(1, n) % MOD;
    return 0;
}