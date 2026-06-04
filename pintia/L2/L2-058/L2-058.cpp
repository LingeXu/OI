#include<iostream>
#define N 100010
using namespace std;
struct parameter {
    int id, score;
}s[N];
bool cmp1(parameter x, parameter y) {
    return x.score > y.score || (x.score == y.score && x.id < y.id);
}
bool cmp2(parameter x, parameter y) {
    return x.score < y.score || (x.score == y.score && x.id < y.id);
}
int main() {
    int n, m;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> s[i].score;
        s[i].id = i + 1;
    }
    cin >> m;
    sort(s, s + n, cmp1);
    cout << s[0].id;
    int now = 0;
    while(now + 1 < n && s[now + 1].score == s[now].score) {
        cout << " " << s[now + 1].id;
        now++;
    }
    cout << '\n';
    sort(s, s + n, cmp2);
    /*for(int i = 0; i < n; i++)
        cout << s[i].id << " " << s[i].score << '\n';*/
    while(m > 0) {
        int x;
        cin >> x;
        int left = 0, right = n;
        while(left < right) {
            int mid = (left + right) / 2;
            if(s[mid].score <= x) {
                left = mid + 1;
            }
            else    right = mid;
        }
        if(left == n)
            cout << 0 << '\n';
        else    cout << s[left].id << '\n';
        m--;
    }
    return 0;
}