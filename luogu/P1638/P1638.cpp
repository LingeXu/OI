#include <bits/stdc++.h>
#define N 1000010
#define M 2020
using namespace std;
int n, m;
int a[N], cnt[M];
int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++)  cin >> a[i];
    int ans = n, record = 0;
    int left_ans = 0, right_ans = n - 1;
    int j = 0;
    for(int i = 0; i < n; i++) {
        while(record < m && j < n) {
            if(++cnt[a[j]] == 1) 
                record++;
            j++;
        }
        if(record == m) {
            int now = j - i;
            if(now < ans) {
                ans = now;
                left_ans = i;
                right_ans = j - 1;
            }
            if(--cnt[a[i]] == 0)
                record--;
            continue;
        }
        if(j == n)  break;
    }
    cout << left_ans + 1 << ' ' << right_ans + 1;
    return 0;
}