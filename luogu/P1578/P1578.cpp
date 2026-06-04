#include <bits/stdc++.h>
#define L 30030
#define W 30030
#define N 5050
typedef long long ll;
using namespace std;
int l, w, n;
ll ans = 0;
struct obstacle {
    int x, y;
}ob[N];
bool CmpByX(obstacle a, obstacle b) {
    return a.x < b.x || (a.x == b.x && a.y < b.y);
}
bool CmpByY(obstacle a, obstacle b) {
    return a.y < b.y || (a.y == b.y && a.x < b.x);
}
int main() {
    cin >> l >> w >> n;
    ob[1] = {0, 0};
    ob[2] = {0, w};
    ob[3] = {l, 0};
    ob[4] = {l, w};
    for(int i = 1; i <= n; i++) 
        cin >> ob[i + 4].x >> ob[i + 4].y;
    sort(ob + 1, ob + n + 5, CmpByX);
    int Left1, Right1;
    for(int i = 1; i <= n + 4; i++) {
        int up1 = w, down1 = 0;
        Left1 = ob[i].x;
        for(int j = i + 1; j <= n + 4; j++) {
            Right1 = ob[j].x;
            ans = max(ans, 1LL * (Right1 - Left1) * (up1 - down1));
            if(ob[j].y >= ob[i].y)   up1 = min(up1, ob[j].y);
            else if(ob[j].y < ob[i].y)   down1 = max(down1, ob[j].y); 
        }
    }
    int Left2, Right2;
    for(int i = n + 4; i >= 1; i--) {
        int up2 = w, down2 = 0;
        Right2 = ob[i].x;
        for(int j = i - 1; j >= 1; j--) {
            Left2 = ob[j].x;
            ans = max(ans, 1LL * (Right2 - Left2) * (up2 - down2));
            if(ob[j].y >= ob[i].y)   up2 = min(up2, ob[j].y);
            else if(ob[j].y < ob[i].y)   down2 = max(down2, ob[j].y); 
        }
    }
    sort(ob + 1, ob + n + 5, CmpByY);
    for(int i = 1; i <= n + 3; i++)
        ans = max(ans, 1LL * (ob[i + 1].y - ob[i].y) * l);
    cout << ans;
    return 0;
}