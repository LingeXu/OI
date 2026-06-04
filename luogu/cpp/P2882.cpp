#include <bits/stdc++.h>
#define N 5050
using namespace std;
int n;
char c;
int original[N], diff[N], change[N];
int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> c;
        original[i] = (c == 'B' ? 0 : 1);
    }
    int min_m = N, k = 1;
    for(int i = 1; i <= n; i++) {
        memset(diff, 0, sizeof(diff));
        memset(change, 0, sizeof(change));
        int operation = 0;
        bool ok = true;
        for(int j = 1; j <= n; j++) {
            change[j] = change[j - 1] + diff[j];
            if(!((original[j] + change[j]) & 1)) {
                if(j + i > n + 1) {
                    ok = false;
                    break;
                }
                operation++;
                change[j]++;
                diff[j + i]--;
            }
        }
        if(ok && operation < min_m) {
            min_m = operation;
            k = i;
        }
    }
    cout << k << ' ' << min_m;
    return 0;
}