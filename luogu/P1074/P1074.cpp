#include <bits/stdc++.h>
#define N 9
using namespace std;
int origin = 0, ans = -1;
int in[N][N];
bool row[N][N + 1], col[N][N + 1], box[N][N + 1];
void FindBestCell(int& x, int& y) {
    int min_choice = 10;
    int best_x = -1, best_y = -1;
    for(x = 0; x < N; x++) {
        for(y = 0; y < N; y++) {
            if(in[x][y] == 0) {
                int choice = 0;
                for(int i = 1; i <= 9; i++) 
                    if(!row[x][i] && !col[y][i] && !box[(x / 3) * 3 + y / 3][i]) 
                        choice++;
                if(choice < min_choice) {
                    min_choice = choice;
                    best_x = x;
                    best_y = y;
                } 
            }
        }
    }
    x = best_x;
    y = best_y;
}
int GetCoe(int x, int y) {
    int dist = max(abs(x - 4), abs(y - 4));
    return 10 - dist;
}
void dfs(int sum) {
    int x, y;
    FindBestCell(x, y);
    if(x == -1 && y == -1) {
        ans = max(ans, sum);
        return;
    }
    for(int i = 1; i <= 9; i++) {
        if(!row[x][i] && !col[y][i] && !box[(x / 3) * 3 + y / 3][i]) {
            in[x][y] = i;
            row[x][i] = 1;
            col[y][i] = 1;
            box[(x / 3) * 3 + y / 3][i] = 1;
            dfs(sum + GetCoe(x, y) * i);
            in[x][y] = 0;
            row[x][i] = 0;
            col[y][i] = 0;
            box[(x / 3) * 3 + y / 3][i] = 0;
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> in[i][j];
            if(in[i][j] != 0) {
                row[i][in[i][j]] = 1;
                col[j][in[i][j]] = 1;
                box[(i / 3) * 3 + j / 3][in[i][j]] = 1;
                origin += GetCoe(i, j) * in[i][j];
            }
        }
    }
    dfs(0);
    if(ans == -1)
        cout << -1;
    else
        cout << ans + origin;
    return 0;
}