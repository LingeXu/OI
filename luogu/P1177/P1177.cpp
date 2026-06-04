#include <bits/stdc++.h>
#define N 100010
using namespace std;
int n;
int a[N], tmp[N];
void merge_sort(int l, int mid, int r) {
    int i = l, j = mid + 1, k = 1;
    while(i <= mid && j <= r) {
        if(a[i] <= a[j])
            tmp[k++] = a[i++];
        else    tmp[k++] = a[j++];
    }
    while(i <= mid) 
        tmp[k++] = a[i++];
    while(j <= r) 
        tmp[k++] = a[j++];
    for(int i = l; i <= r; i++)
        a[i] = tmp[i - l + 1];
}
void merge(int l, int r) {
    if(l >= r)  return;
    int mid = l + (r - l) / 2;
    merge(l, mid);
    merge(mid + 1, r);
    merge_sort(l, mid, r);
}
int main() {
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    merge(1, n);
    for(int i = 1; i <= n; i++)
        cout << a[i] << ' ';
    return 0;
}