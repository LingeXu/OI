#include <bits/stdc++.h>
#define N 1010
typedef long long ll;
using namespace std;
int n;
int record_x[2 * N], record_y[2 * N], final_x[2 * N], final_y[2 * N];
int ans[2* N][2 * N];
struct pos {
    int x, y;
}p[2 * N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    int now1_x = 0;
    int now1_y = 0;
    for(int i = 0; i < n; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        p[2 * i].x = x1;
        p[2 * i].y = y2;
        p[2 * i + 1].x = x2;
        p[2 * i + 1].y = y1;
        record_x[now1_x++] = x1;
        record_x[now1_x++] = x2;
        record_y[now1_y++] = y2;
        record_y[now1_y++] = y1;
    }
    sort(record_x, record_x + 2 * n);
    sort(record_y, record_y + 2 * n);
    int now2_x = 0;
    int now2_y = 0;
    for(int i = 0; i < 2 * n; i++) 
        if(i == 0 || record_x[i] != record_x[i - 1])
            final_x[now2_x++] = record_x[i];
    for(int i = 0; i < 2 * n; i++) 
        if(i == 0 || record_y[i] != record_y[i - 1])
            final_y[now2_y++] = record_y[i];
    for(int i = 0; i < n; i++) {
        int pos1_x = lower_bound(final_x, final_x + now2_x, p[2 * i].x) - final_x;
        int pos1_y = lower_bound(final_y, final_y + now2_y, p[2 * i].y) - final_y;
        int pos2_x = lower_bound(final_x, final_x + now2_x, p[2 * i + 1].x) - final_x;
        int pos2_y = lower_bound(final_y, final_y + now2_y, p[2 * i + 1].y) - final_y;
        //cout << pos1_x << ' ' << pos1_y << ' ' << pos2_x << ' ' << pos2_y << '\n';
        for(int j = pos1_x; j < pos2_x; j++)
            for(int k = pos1_y; k < pos2_y; k++)
                ans[j][k] = 1;
    }
    ll sum = 0;
    for(int i = 0; i < 2 * n; i++) 
        for(int j = 0; j < 2 * n; j++)
            if(ans[i][j])  
                sum += 1LL * (final_x[i + 1] - final_x[i]) * (final_y[j + 1] - final_y[j]);
    cout << sum;
    return 0;
}