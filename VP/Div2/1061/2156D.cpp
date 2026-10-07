#include <bits/stdc++.h>
using namespace std;
int t, n;
int cnt(int n, int already, int cur) {
    int res = 0;
    int now = already + (1 << cur);
    for(int i = 1; i <= n; i++)
        if(i % (1 << (cur + 1)) == now)
            res++;
    return res;
}
void solve() {
    cin >> n;
    vector<int> record, zero, one;
    for(int i = 1; i <= n - 1; i++)
        record.push_back(i);
    int cur = 0, already = 0;
    while((1 << cur) <= n) {
        /*if((int)record.size() == 0) {
            cout << "! " << (1 << cur) << endl;
            return;
        }*/
        zero.clear();
        one.clear();
        for(int i : record) {
            cout << "? " << i << ' ' << (1 << cur) << endl;
            int rep;
            cin >> rep;
            if(rep == 0)    zero.push_back(i);
            else    one.push_back(i);
        }     
        record.clear();  
        int aim = cnt(n, already, cur);
        if((int)one.size() < aim) {
            already += (1 << cur);
            for(int i : one)
                record.push_back(i);
        }
        else {
            for(int i : zero)
                record.push_back(i);
        }
        cur++;
    }
    cout << "! " << already << endl;
}
int main() {
    cin >> t;
    while(t--)  solve();
    return 0;
}