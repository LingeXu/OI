#include <bits/stdc++.h>
#define N 500050
typedef long long ll;
using namespace std;
int n;
int a[N], tmp[N];
ll merge_sort(int l, int mid, int r) {
    int i = l, j = mid + 1, k = 1;
    ll cnt = 0;
    while(i <= mid && j <= r) {
        if(a[i] <= a[j])
            tmp[k++] = a[i++];
        else {
            cnt += 1LL * (mid - i + 1);
            tmp[k++] = a[j++];
        }
    }
    while(i <= mid) 
        tmp[k++] = a[i++];
    while(j <= r)
        tmp[k++] = a[j++];
    for(int i = l; i <= r; i++)
        a[i] = tmp[i - l + 1];
    return cnt;
}
ll merge(int l, int r) {
    if(l >= r)  return 0;
    int mid = l + (r - l) / 2;
    return merge(l, mid) + merge(mid + 1, r) + merge_sort(l, mid, r);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    cout << merge(1, n);
    return 0;
}