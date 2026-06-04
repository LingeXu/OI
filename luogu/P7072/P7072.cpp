#include <bits/stdc++.h>
#define N 100010
#define MAXS 610
using namespace std;
int n, w;
int a[N], sum[MAXS];
int main() {
    cin >> n >> w;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        sum[a[i]]++;
        int p = max(1, (i + 1) * w / 100);
        for(int j = 600; j >= 0; j--) {
            p -= sum[j];
            if(p <= 0) {
                cout << j << ' ';
                break;
            }
        }
    }
    return 0;
}