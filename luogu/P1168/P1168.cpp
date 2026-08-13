#include <bits/stdc++.h>
using namespace std;
int n, mid;
priority_queue<int, vector<int>, less<int> > p1;
priority_queue<int, vector<int>, greater<int> > p2;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if(i == 0) {
            mid = x;
            cout << x << '\n';
        }
        else {
            if(x < mid)    p1.push(x); 
            else    p2.push(x);   
            if(i % 2 != 0)  continue;
            while((int)p1.size() > (int)p2.size())  {
                p2.push(mid);
                mid = p1.top();
                p1.pop();
            }
            while((int)p2.size() > (int)p1.size())  {
                p1.push(mid);
                mid = p2.top();
                p2.pop();
            }
            cout << mid << '\n';
        }
    }
    return 0;
}