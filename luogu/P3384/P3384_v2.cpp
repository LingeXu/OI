#include <bits/stdc++.h>
#define N 100010
using namespace std;
int n, m, r, p;
int val[N];
void OP1(int x, int y, int z) {
    int rt = lca(x, y);
    dfs(rt, 0, z);
    dfs(x, 0, -z);
    dfs(y, 0, -z);
    val[x] += z;
    
}   
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m >> r >> p;
    for(int i = 1; i <= n; i++) 
        cin >> val[i];
    for(int i = 0; i < m; i++) {
        int op;
        cin >> op;
        if(op == 1) {
            int x, y, z;
            cin >> x >> y >> z;
            void OP1(x, y, z);
        }
        else if(op == 2) {
            int x, y;
            cin >> x >> y;

        }
        else if(op == 3) {
            int x, z;
            cin >> x >> z;
        }
        else {
            int x;
            cin >> x;
        }
    }
    return 0;
}