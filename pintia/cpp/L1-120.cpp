#include<iostream>
using namespace std;
int main() {
    int n;
    string s;
    cin >> n >> s;
    while(n > 0) {
        int op;
        cin >> op;
        if(op == 1) {
            string pat;
            cin >> pat;
            int pos = 0, find_time = 0;
            while(1) {
                pos = (int)s.find(pat, pos);
                if(pos == -1 && find_time == 0) {
                    cout << -1;
                    break;
                }
                if(pos != -1 && find_time < 3) {
                    find_time++;
                    cout << pos;
                    if((int)s.find(pat, pos + 1) != -1 && find_time <= 2)
                        cout << " ";
                }
                else    break;
                pos++;
            }
            cout << '\n';
        }
        else if(op == 2) {
            int p;
            string s2;
            cin >> p >> s2;
            s = s.insert(p, s2);
            cout << s << '\n';
        }
        else if(op == 3) {
            int l,r;
            cin >> l >> r;
            string pat_to_reverse = s.substr(l, r - l + 1);
            string pat_reversed;
            for(int i = pat_to_reverse.size() - 1; i >= 0; i--) 
                pat_reversed += pat_to_reverse[i];
            s.erase(l, r - l + 1);
            //cout << s << '\n';
            s.insert(l, pat_reversed);
            cout << s << '\n';
        }
        n --;
    }
    return 0;
}