#include <bits/stdc++.h>
#define N 250
using namespace std;
int n;
int a[N], dp_max[N], dp_tail_max[N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    dp_max[1] = dp_tail_max[1] = a[1];
    for(int i = 2; i <= n; i++) {
        if(a[i] > dp_tail_max[i - 1]) 
            dp_tail_max[i] = a[i];
        else if(a[i] == dp_tail_max[i - 1])
            dp_tail_max[i] = a[i] + 1;
        else    
        if(a[i] > dp_max[i - 1]) {
            dp_max[i] = a[i];
            continue;
        }
        if(a[i] == dp_max[i - 1]) {
            if(dp_tail_max[i - 1] == a[i]) {
                dp_max[i] = a[i] + 1;
                continue;
            }
            else    dp_max[i] = dp_max[i - 1];
        }
        if(a[i] < dp_max[i - 1]) {
            dp_max[i] = dp_max[i - 1];
            contiue;
        }
    }
    cout << dp_max[n];
    return 0;
}