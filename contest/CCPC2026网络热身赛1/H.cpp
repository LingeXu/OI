#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int resp;
    int max_dist1 = 0, ep1 = -1;
    for(int i = 2; i <= n; i++) {
        cout << "? " << 1 << ' ' << i << endl;
        cin >> resp;
        if(resp > max_dist1) {
            max_dist1 = resp;
            ep1 = i;
        }
    }
    int max_dist2 = 0, ep2 = -1;
    vector<int> to_ep1(n + 1);
    for(int i = 1; i <= n; i++) {
        cout << "? " << ep1 << ' ' << i << endl;
        cin >> resp;
        to_ep1[i] = resp;
        if(resp > max_dist2) {
            max_dist2 = resp;
            ep2 = i;
        }
    }
    int d = to_ep1[ep2];
    int joint, aim, max_out = 0;
    bool find_aim = false;
    vector<int> out(n + 1, 0);
    for(int i = 1; i <= n; i++) {
        cout << "? " << ep2 << ' ' << i << endl;
        cin >> resp;
        if(resp + to_ep1[i] == d) 
            out[i] = 0;
        else {
            out[i] = (resp + to_ep1[i] - d) / 2;
            max_out = max(max_out, out[i]);
            if(!find_aim) {
                aim = to_ep1[i] - out[i];
                find_aim = true;          
            }
        }
    }
    for(int i = 1; i <= n; i++) {
        if(to_ep1[i] == aim) {
            joint = i;
            break;
        }
    }
    cout << "!\n";
    int cur1 = 1, cur2 = 1, pre1 = ep1, pre2 = joint;
    while(cur1 <= d) {
        for(int i = 1; i <= n; i++) {
            if(to_ep1[i] == cur1 && out[i] == 0) {
                cout << pre1 << ' ' << i << endl;
                pre1 = i;
                cur1++;
                break;
            }
        }
    }
    while(cur2 <= max_out) {
        for(int i = 1; i <= n; i++) {
            if(out[i] == cur2) {
                cout << pre2 << ' ' << i << endl;
                pre2 = i;
                cur2++;
                break;
            }
        }
    }
    return 0;
}