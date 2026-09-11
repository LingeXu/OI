#include <bits/stdc++.h>
using namespace std;
int t, r, g, b;
void solve() {
    cin >> r >> g >> b;
    int gb = 0, rb = 0, rg = 0;
    while((r > 0) + (g > 0) + (b > 0) >= 2) {
        if(r <= g && r <= b) {
            gb++;
            g--;
            b--;
            continue;
        }
        if(g <= r && g <= b) {
            rb++;
            r--;
            b--;
            continue;
        }
        rg++;
        r--;
        g--;
    }
    if(r > 0) {
        cout << 'R';
        for(int i = 1; i <= rb; i++)
            cout << "BR";
        for(int i = 1; i <= rg; i++)
            cout << "GR";
        if(rg != 0) {
            for(int i = 1; i <= gb; i++)
                cout << "GB"; 
            cout << '\n';
            return;
        }
        for(int i = 1; i <= gb; i++)
            cout << "BG"; 
        cout << '\n';
        return;
    }
    if(g > 0) {
        cout << 'G';
        for(int i = 1; i <= rg; i++)
            cout << "RG";
        for(int i = 1; i <= gb; i++)
            cout << "BG";
        if(gb != 0) {
            for(int i = 1; i <= rb; i++)
                cout << "BR"; 
            cout << '\n';
            return;
        }
        for(int i = 1; i <= rb; i++)
            cout << "RB"; 
        cout << '\n';
        return;
    }
    if(b > 0) {
        cout << 'B';
        for(int i = 1; i <= rb; i++)
            cout << "RB";
        for(int i = 1; i <= gb; i++)
            cout << "GB";
        if(gb != 0) {
            for(int i = 1; i <= rg; i++)
                cout << "GR"; 
            cout << '\n';
            return;
        }
        for(int i = 1; i <= rg; i++)
            cout << "RG"; 
        cout << '\n';
        return;
    }
    for(int i = 1; i <= rb; i++)
        cout << "RB";
    for(int i = 1; i <= gb; i++)
        cout << "GB"; 
    if(gb != 0) {
        for(int i = 1; i <= rg; i++)
            cout << "GR";
        cout << '\n';
        return;
    }
    for(int i = 1; i <= rg; i++)
        cout << "RG";
    cout << '\n';
    return;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--)  solve();
    return 0;
}