#include <bits/stdc++.h>
#define N 500050
typedef long long ll;
using namespace std;
int n;
int a[N];
ll merge_sort(int l, int r, int mid) {
    int i = l, j = mid + 1, idx = 0;
    ll cnt = 0;
    vector<int> tmp(r - l + 1);
    while(i <= mid && j <= r) {
        if(a[i] <= a[j]) {
            tmp[idx++] = a[i];
            i++;
        }
        else {
            tmp[idx++] = a[j];
            cnt += 1LL * (mid - i + 1);
            j++;
        }
    }
    while(i <= mid) 
        tmp[idx++] = a[i++];
    while(j <= r) 
        tmp[idx++] = a[j++];
    for(int i = 0; i < r - l + 1; i++) 
        a[i + l] = tmp[i];
    return cnt;
}
ll merge(int l, int r) {
    if(l >= r)  return 0;
    int mid = l + (r - l) / 2;
    return merge(l, mid) + merge(mid + 1, r) + merge_sort(l, r, mid);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    cout << merge(1, n);
    return 0;
}