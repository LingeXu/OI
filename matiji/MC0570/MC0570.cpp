#include <bits/stdc++.h>
#define N 10010
using namespace std;
int n, q, top = 0;
int a[N], L[N], R[N], s[N], idx[N];
int  main() {
    cin >> n >> q;
    for(int i = 1; i <= n; i++) 
        cin >> a[i];
    for(int i = 1; i <= n; i++) {
        while(top > 0 && s[top] < a[i]) 
            R[idx[top--]] = i;
        s[++top] = a[i];
        idx[top] = i;
    }
    top = 0;
    memset(s, 0, sizeof(s));
    for(int i = n; i >= 1; i--) {
        while(top > 0 && s[top] > a[i]) 
            L[idx[top--]] = i;
        s[++top] = a[i];
        idx[top] = i;
    }

    /*for(int i = 1; i <= n; i++)
        cout << L[i] << ' ' << R[i] << '\n';*/
        
    for(int i = 1; i <= q; i++) {
        int l, r;
        cin >> l >> r;
        bool ok = false;
        for(int j = l; j <= r; j++) {
            if(L[j] >= l && R[j] <= r) {
                ok =true;
                break;
            }
        }
        cout << (ok ? "Yes" : "No") << '\n';
    }
    return 0;
}