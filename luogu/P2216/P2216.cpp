#include <bits/stdc++.h>
#define A 1010
#define B 1010
typedef long long ll;
using namespace std;
int a, b, k;
ll ans = 1e9;
ll mat[A][B], row_max[A][B], row_min[A][B], square_max[A][B], square_min[A][B];
deque< pair<int, int> > dq_row_max, dq_row_min, dq_square_max, dq_square_min;
int main() {
    cin >> a >> b >> k;
    for(int i = 1; i <= a; i++)
        for(int j = 1; j <= b; j++)
            cin >> mat[i][j];
    for(int i = 1; i <= a; i++) {
        dq_row_max.clear();
        for(int j = 1; j <= b; j++) {
            while(!dq_row_max.empty() && mat[i][j] > dq_row_max.back().first)
                dq_row_max.pop_back();
            dq_row_max.push_back({mat[i][j], j});
            while(dq_row_max.front().second < j - k + 1)
                dq_row_max.pop_front();
            if(j >= k) 
                row_max[i][j - k + 1] = dq_row_max.front().first;
        }
    }
    for(int i = 1; i <= a; i++) {
        dq_row_min.clear();
        for(int j = 1; j <= b; j++) {
            while(!dq_row_min.empty() && mat[i][j] < dq_row_min.back().first)
                dq_row_min.pop_back();
            dq_row_min.push_back({mat[i][j], j});
            while(dq_row_min.front().second < j - k + 1)
                dq_row_min.pop_front();
            if(j >= k) 
                row_min[i][j - k + 1] = dq_row_min.front().first;
        }
    }
    for(int i = 1; i <= b - k + 1; i++) {
        dq_square_max.clear();
        for(int j = 1; j <= a; j++) {
            while(!dq_square_max.empty() && row_max[j][i] > dq_square_max.back().first)
                dq_square_max.pop_back();
            dq_square_max.push_back({row_max[j][i], j});
            while(dq_square_max.front().second < j - k + 1)
                dq_square_max.pop_front();
            if(j >= k)
                square_max[j - k + 1][i] = dq_square_max.front().first;
        }
    }
    for(int i = 1; i <= b - k + 1; i++) {
        dq_square_min.clear();
        for(int j = 1; j <= a; j++) {
            while(!dq_square_min.empty() && row_min[j][i] < dq_square_min.back().first)
                dq_square_min.pop_back();
            dq_square_min.push_back({row_min[j][i], j});
            while(dq_square_min.front().second < j - k + 1)
                dq_square_min.pop_front();
            if(j >= k)
                square_min[j - k + 1][i] = dq_square_min.front().first;
        }
    }
    for(int i = 1; i <= a - k + 1; i++)
        for(int j = 1; j <= b - k + 1; j++)
            ans = min(ans, square_max[i][j] - square_min[i][j]);
    cout << ans;
    return 0;
}