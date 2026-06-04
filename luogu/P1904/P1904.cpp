#include <bits/stdc++.h>
#define N 5050
using namespace std;
struct vertex {
    int x, h;
}v[2 * N], v_final[2 * N];
bool cmp(vertex a, vertex b) {
    return a.x < b.x || (a.x == b.x && a.h > b.h);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int l, h, r;
    int id1 = 1;
    while(cin >> l >> h >> r) {
        v[id1++] = {l, h};
        v[id1++] = {r, h}; 
    }
    sort(v + 1, v + id1, cmp);
    int id2 = 1;
    for(int i = 1; i <= id1; i++) {
        v_final[id2++] = v[i];
        while(i + 1 <= id1 && v[i].x == v[i + 1].x)
            i++;
    }
    for(int i = 1; i <= id2; i++) 
        if(i == 1 || v_final[i].h != v_final[i - 1].h)
            cout << v_final[i].x << ' ' << v_final[i].h << ' ';
    return 0;
}