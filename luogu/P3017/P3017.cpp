#include <bits/stdc++.h>
#define R 505
#define C 505
typedef long long ll;
using namespace std;
int r, c, a, b;
int n[R][C];
ll sum[R][C];
ll GetSum(int x1, int y1, int x2, int y2) {
    return sum[x2][y2] - sum[x2][y1 - 1] - sum[x1 - 1][y2] + sum[x1 - 1][y1 - 1];
}
bool check(int x) {
    int rows_start = 1;
    int rows_cnt = 0;
    for(int rows_end = rows_start; rows_end <= r; rows_end++) {
        int cols_start = 1;
        int cols_cnt = 0;
        for(int cols_end = cols_start; cols_end <= c; cols_end++) {
            if(GetSum(rows_start, cols_start, rows_end, cols_end) >= x) {
                if(++cols_cnt == b) {
                    rows_cnt++;
                    rows_start = rows_end + 1;
                    break;
                }
                cols_start = cols_end + 1;
            }
        }
    }   
    return rows_cnt >= a;
}
int main() {
    cin >> r >> c >> a >> b;
    for(int i = 1; i <= r; i++) {
        for(int j = 1; j <= c; j++) {
            cin >> n[i][j];
            sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + n[i][j];
        }
    }
    ll Left = 0, Right = sum[r][c] / (a * b);
    ll ans = 0;
    //cout << check(3) << '\n';
    while(Left <= Right) {
        ll Mid = Left + (Right - Left) / 2;
        if(check(Mid)) {
            ans = Mid;
            Left = Mid + 1;
        }
        else    Right = Mid - 1;
    }
    cout << ans;
    return 0;
}