#include <bits/stdc++.h>
#define N 3000030
using namespace std;
int n, top = 0;
int a[N], ans[N], s[N], id[N];
int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        while(top > 0 && a[i] > s[top])
            ans[id[top--]] = i;
        s[++top] = a[i];
        id[top] = i;
    }
    for(int i = 1; i <= n; i++)
        cout << ans[i] << ' ';
    return 0;
}