#include <bits/stdc++.h>
#define N 1000010
#define K 10
using namespace std;
int n, k;
vector<int> a[K];
int mew(int x, int y, int z) {
    int res = 0;
    while(x == res || y == res || z == res)
        res++;
    return res;
}
bool equal(vector<int>& a, vector<int>& b) {
    if((int)a.size() != (int)b.size())    return false;
    for(int i = 0; i < (int)a.size(); i++)
        if(a[i] != b[i])
            return false;
    return true;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a[0].push_back(x);
    }
    for(int i = 1; i <= 10; i++)
        for(int j = 0; j < n; j++)
            a[i].push_back(mew(a[i - 1][j], a[i - 1][(j + 1) % n], a[i - 1][(j + n - 1) % n]));
    if(k <= 10)
        for(int i = 0; i < n; i++)
            cout << a[k][i] << ' ';
    else {
        int cycle_start = 0;
        while(!equal(a[cycle_start], a[cycle_start + 2]))    cycle_start++;
        if((k - cycle_start) & 1)
            for(int i = 0; i < n; i++)
                cout << a[cycle_start + 1][i] << ' ';
        else
            for(int i = 0; i < n; i++)
                cout << a[cycle_start][i] << ' ';
    }
    return 0;
}