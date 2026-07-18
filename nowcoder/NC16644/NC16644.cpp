#include <bits/stdc++.h>
using namespace std;
int p1, p2, p3;
string s;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> p1 >> p2 >> p3 >> s;
    int pos = (int)s.find('-');
    while(pos != - 1) {
        if(pos == 0) {
            pos = (int)s.find(1, '-');
            continue;
        }
        if(pos == s.size() - 1) break;
        int pre = pos - 1, next = pos + 1;
        if(!((islower(s[pre]) && islower(s[next])) || (isdigit(s[pre]) && isdigit(s[next])))) {
            pos = (int)s.find(pos + 1, '-');
            continue;
        }
        if(s[pre] + 1 == s[next]) {
            s.erase(pos);
            pos = (int)s.find(pos, '-');
            continue;
        }
        int interval = s[next] - s[pre] - 1;
        s.erase(pos);
        string n;
        if(p1 == 3) {
            for(int i = 1; i <= interval * p2; i++)
                n += '*';
        }
        else if(p1 == 1) {
            if(p3 == 1) {
                char now = s[pre];
                for(int i = 1; i <= interval; i++) {
                    now++;
                    for(int j = 1; j <= p2; j++)
                        n += now;
                }
            }
            else if(p3 == 2) {
                char now = s[next];
                for(int i = 1; i <= interval; i++) {
                    now--;
                    for(int j = 1; j <= p2; j++)
                        n += now;
                }
            }
        }
        else if(p1 == 2) {
            if(p3 == 1) {

            }
            else if(p3 == 2) {
                
            }
        }
        s.insert(pos, n);
        pos = (int)s.find(pos, '-');
    }
    return 0;
}