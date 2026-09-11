#include <bits/stdc++.h>
using namespace std;
int t, r, g, b;
int cmp(int r, int g, int b) {
    if(r >= g && r >= b)    return 1;
    if(g >= r && g >= b)    return 2;
    if(b >= r && b >= g)    return 3;
    return -1;
}
void solve() {
    cin >> r >> g >> b;
    if(r > 0 && g == 0 && b == 0) {
        cout << 'R' << '\n';
        return;
    }
    if(r == 0 && g > 0 && b == 0) {
        cout << 'G' << '\n';
        return;
    }
    if(r == 0 && g == 0 && b > 0) {
        cout << 'B' << '\n';
        return;
    }
    if(r == 1 && g == 1 && b == 0) {
        cout << "RG" << '\n';
        return;
    }
    if(r == 1 && g == 0 && b == 1) {
        cout << "RB" << '\n';
        return;
    }
    if(r == 0 && g == 1 && b == 1) {
        cout << "GB" << '\n';
        return;
    }
    string s;
    if(cmp(r, g, b) == 1) {
        s += 'R';
        r--;
        if(g >= b && g > 0) {
            s += 'G';
            g--;
            if(r >= b && r > 0) {
                s += 'R';
                r--;
            }
            else if(b > r && b > 0){
                s += 'B';
                b--;
            }
            else {
                cout << s << '\n';
                return;
            }
        }
        else if(b > g && b > 0){
            s += 'B';
            b--;
            if(r >= g && r > 0) {
                s += 'R';
                r--;
            }
            else if(g > r && g > 0){
                s += 'G';
                g--;
            }
            else {
                cout << s << '\n';
                return;
            }
        }
        else {
            cout << s << '\n';
            return;
        }
    }
    else if(cmp(r, g, b) == 2) {
        s += 'G';
        g--;
        if(r >= b && r > 0) {
            s += 'R';
            r--;
            if(g >= b && g > 0) {
                s += 'G';
                g--;
            }
            else if(b > g && b > 0){
                s += 'B';
                b--;
            }
            else {
                cout << s << '\n';
                return;
            }
        }
        else if(b > r && b > 0){
            s += 'B';
            b--;
            if(r >= g && r > 0) {
                s += 'R';
                r--;
            }
            else if(g > r && g > 0){
                s += 'G';
                g--;
            }
            else {
                cout << s << '\n';
                return;
            }
        }
        else {
            cout << s << '\n';
            return;
        }
    }
    else {
        s += 'B';
        b--;
        if(g >= r && g > 0) {
            s += 'G';
            g--;
            if(b >= r && b > 0) {
                s += 'B';
                b--;
            }
            else if(r > b && r > 0){
                s += 'R';
                r--;
            }
            else {
                cout << s << '\n';
                return;
            }
        }
        else if(r > g && r > 0){
            s += 'R';
            r--;
            if(b >= g && b > 0) {
                s += 'B';
                b--;
            }
            else if(g > b && g > 0){
                s += 'G';
                g--;
            }
            else {
                cout << s << '\n';
                return;
            }
        }
        else {
            cout << s << '\n';
            return;
        }
    }

    //cout << s << '\n';

    while(1) {
        int l = (int)s.size();
        if(s[l - 1] != s[l - 3]) {
            if((s[l - 1] == 'R' && s[l - 3] == 'G') || (s[l - 1] == 'G' && s[l - 3] == 'R')){
                if(b > 0) {
                    s += 'B';
                    b--;
                }
                else {
                    cout << s << '\n';
                    return;
                }
                continue;
            }
            if((s[l - 1] == 'B' && s[l - 3] == 'G') || (s[l - 1] == 'G' && s[l - 3] == 'B')){
                if(r > 0) {
                    s += 'R';
                    r--;
                }
                else {
                    cout << s << '\n';
                    return;
                }
                continue;
            }
            if((s[l - 1] == 'R' && s[l - 3] == 'B') || (s[l - 1] == 'B' && s[l - 3] == 'R')){
                if(g > 0) {
                    s += 'G';
                    g--;
                }
                else {
                    cout << s << '\n';
                    return;
                }
                continue;
            }
        }
        else {
            if(s[l - 1] == 'R') {
                if(g > b && g > 0) {
                    s += 'G';
                    g--;
                }
                else if(b > g && b > 0){
                    s += 'B';
                    b--;
                }
                else if(b == g && b > 0 && s[l - 2] == 'G') {
                    s += 'G';
                    g--;
                }
                else if(b == g && b > 0 && s[l - 2] == 'B') {
                    s += 'B';
                    b--;
                }
                else {
                    cout << s << '\n';
                    return;
                }
                continue;
            }
            if(s[l - 1] == 'G') {
                if(r > b && r > 0) {
                    s += 'R';
                    r--;
                }
                else if(b > r && b > 0){
                    s += 'B';
                    b--;
                }
                else if(b == r && b > 0 && s[l - 2] == 'R') {
                    s += 'R';
                    r--;
                }
                else if(b == r && b > 0 && s[l - 2] == 'B') {
                    s += 'B';
                    b--;
                }
                else {
                    cout << s << '\n';
                    return;
                }
                continue;
            }
            if(s[l - 1] == 'B') {
                if(r > g && r > 0) {
                    s += 'R';
                    r--;
                }
                else if(g > r && g > 0){
                    s += 'G';
                    g--;
                }
                else if(g == r && g > 0 && s[l - 2] == 'R') {
                    s += 'R';
                    r--;
                }
                else if(g == r && g > 0 && s[l - 2] == 'G') {
                    s += 'G';
                    g--;
                }
                else {
                    cout << s << '\n';
                    return;
                }
                continue;
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--)  solve();
    return 0;
}