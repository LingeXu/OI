#include <bits/stdc++.h>
#define N 8080
using namespace std;
int n, Q;
int t[N];
struct node {
    int val, id;
}a[N];
bool cmp(node x, node y) {
    return x.val < y.val || (x.val == y.val && x.id < y.id);
}
void swap(node& x, node& y) {
    node tmp;
    tmp = x;
    x = y;
    y = tmp;
}
int main() {
    cin >> n >> Q;
    for(int i = 1; i <= n; i++) {
        cin >> a[i].val;
        a[i].id = i;
    }
    sort(a + 1, a + n + 1, cmp);
    for(int i = 1; i <= n; i++) 
        t[a[i].id] = i;
    for(int i = 1; i <= Q; i++) {
        int op;
        cin >> op;
        if(op == 1) {
            int x, v;
            cin >> x >> v;
            int p = t[x];
            if(v > a[p].val) {
                a[p].val = v;
                for(int j = p; j < n; j++) {
                    if(a[j + 1].val < a[j].val || (a[j + 1].val == a[j].val && a[j + 1].id < a[j].id)) {
                        swap(a[j], a[j + 1]);
                        t[a[j].id] = j;
                        t[a[j + 1].id] = j + 1;
                    }
                }
            }
            else if(v < a[p].val) {
                a[p].val = v;
                for(int j = p; j >= 2; j--) {
                    if(a[j].val < a[j - 1].val || (a[j].val == a[j - 1].val && a[j].id < a[j - 1].id)) {
                        swap(a[j], a[j - 1]);
                        t[a[j].id] = j;
                        t[a[j - 1].id] = j - 1;
                    }
                }
            }
            else    continue;
        }
        else if(op == 2) {
            int x;
            cin >> x;
            cout << t[x] << '\n';
        }
    }
    return 0;
}