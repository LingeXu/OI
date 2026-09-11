#include <bits/stdc++.h>
using namespce std;
int t;
struct inf {
    int dianshu, huase;
} a[5], b[5];
bool cmp(inf a, inf b) {
    return a.dianshu > b.dianshu;
}
int judge(vector<inf> &x) {
    sort(x.begin(), x.end(), cmp);
    int importance;
    bool royal_flush;
    if(x[0].dianshu == 13 && x[1].dianshu == 12 && x[2].dianshu == 11 && x[3].dianshu == 10 && x[4].dianshu == 1 && x[0].huase == x[1].huase && x[1].huase == x[2].huase && x[2].huase == x[3].huase && x[3].huase == x[4].huase)
        royal_flush = true;
    bool straight_flush = true;
    for(int i = 0; i < 4; i++) {
        if(!(x[i + 1].dianshu - x[i].dianshu == 1 && x[i + 1].huase == x[i].huase)) {
            straight_flush = false;
            break;
        }
    }
    bool four_of_a_kind = false;
    if(x[0].dianshu == x[1].dianshu && x[1].dianshu == x[2].dianshu && x[2].dianshu == x[3].dianshu)
        four_of_a_kind = true;
    bool full_house =  false;
    if(x[0].dianshu == x[1].dianshu && x[1].dianshu == x[2].dianshu && x[3].dianshu == x[4].dianshu)
        full_house = true;
    bool flush = true;
    for(int i = 0; i < 4; i++) {
        if(x[i].huase != x[i + 1].huase) {
            flush = false;
            break;
        }
    }
    bool straight = true;
    for(int i = 0; i < 4; i++) {
        if(x[i + 1].dianshu - x[i].dianshu == 1) {
            straight = false;
            break;
        }
    }
    
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    while(t--) {
        bool use[14][4][2];
        int importance[2];
        for(int i = 0; i < 8; i++) {
            string s;
            cin >> s;
            cin.ignore();
            int x, y;
            if(s.back() == 'C')
                y = 0;
            else if(s.back() == 'D')
                y = 1;
            else if(s.back() == 'H')
                y = 2;
            else if(s.back() == 'S')
                y = 3;
            if(s.size() == 3)
                x = 10;
            else if(s[0] == 'A')
                x = 1;
            else if(s[0] == 'J')
                x = 11;
            else if(s[0] == 'Q')
                x = 12;
            else if(s[0] == 'K')
                x = 13; 
            else    x = s[0] - '0';
            use[x][y][i < 4] = true;
            if(i < 4)
                a[i] = {x, y};
            else    b[i - 4] = {x, y};
            sort(a, a + 4, cmp);
            sort(b, b + 4, cmp);
        }
    }
    return 0;
}