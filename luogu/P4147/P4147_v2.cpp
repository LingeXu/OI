#include <bits/stdc++.h>
#define N 1010
#define M 1010
using namespace std;
int n, m;
int h[M];
char c[N][M];
int main() {
    cin >> n >> m;
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> c[i][j];
            if(c[i][j] == 'F')
                h[j]++;
            else    h[j] = 0;
        }
        stack<int> s;
        for(int j = 1; j <= m + 1; j++) {
            int cur_h = (j == m + 1 ? 0 : h[j]);
            while(!s.empty() && cur_h < h[s.top()]) {
                int height = h[s.top()];
                s.pop();
                int width;
                if(s.empty())   width = j - 1;
                else    width = j - s.top() - 1;
                ans = max(ans, height * width);
            }
            s.push(j);
        }
    }
    cout << 3 * ans;
    return 0;
}