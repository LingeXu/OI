#include<iostream>
#include<stack>
using namespace std;
stack< pair<int, int> > s;
int main() {
    int n, T;
    cin >> n >> T;
    int cnt = 0, sum = 0;
    double aver = 0.0;
    for(int i = 1; i <= n; i++) {
        int c;
        cin >> c;
        if(c <= T) {
            if(cnt == 0) {
                cout << i;
                cnt++;
            }
            else    cout << " " << i;
        }
        else {
            s.push({c, i});
            sum += c;
        }
    }
    aver = 1.0 * sum / s.size();
    sum = 0;
    while(!s.empty()) {
        stack< pair<int, int> > s1;
        while(!s.empty()) {
            auto x = s.top();
            if(x.first <= aver) {
                if(cnt == 0) {
                    cout << x.second;
                    cnt++;
                }
                else    cout << " " << x.second;
                s.pop();
            }
            else {
                s1.push(x);
                sum += x.first;
                s.pop();
            }
        }
        s = s1;
        aver = 1.0 * sum / s1.size();
        sum = 0;
    }
    return 0;
}