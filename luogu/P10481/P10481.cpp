#include <bits/stdc++.h>
#define M 10
using namespace std;
int n;
bool stop = false;
char sudoku[M][M];
struct pos {
    int x, y;
};
bitset<M> row[M], col[M], box[M];
bool findBestCell(int& x, int& y) {
    int min_choice = 10, best_x = -1, best_y = -1;
    for(int i = 1; i < M; i++) {
        for(int j = 1; j < M; j++) {
            if(sudoku[i][j] == '0') {
                int choice = 0;
                for(int num = 1; num < M; num++)
                    if(!row[i][num] && !col[j][num] && !box[(i - 1) / 3 * 3 + (j - 1) / 3 + 1][num])
                        choice++;
                if(choice == 0)
                    return false;
                if(choice < min_choice) {
                    min_choice = choice;
                    best_x = i;
                    best_y = j;
                }
            }
        }
    }
    x = best_x;
    y = best_y;
    return best_x != -1;
}
void dfs() {
    if(stop)    return;
    int x, y;
    if(!findBestCell(x, y)) {
        stop = true;
        for(int i = 1; i < M; i++)
            for(int j = 1; j < M; j++)
                if(sudoku[i][j] == '0')
                    stop = false;
        if(stop) {
            for(int i = 1; i < M; i++) {
                for(int j = 1; j < M; j++)
                    cout << sudoku[i][j];
                cout << '\n';
            }
        }
        return;
    }
    int bid = (x - 1) / 3 * 3 + (y - 1) / 3 + 1;
    for(int num = 1; num < M; num++) {
        if(!row[x][num] && !col[y][num] && !box[bid][num]) {
            bitset<M> old_row = row[x];
            bitset<M> old_col = col[y];
            bitset<M> old_box = box[bid];
            sudoku[x][y] = '0' + num;
            row[x][num] = 1;
            col[y][num] = 1;
            box[bid][num] = 1;
            dfs();
            row[x] = old_row;
            col[y] = old_col;
            box[bid] = old_box;
            sudoku[x][y] = '0';
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    while(n > 0) {
        stop = false;
        for(int i = 1; i <= 9; i++) {
            row[i].reset();
            col[i].reset();
            box[i].reset();
        }   
        for(int i = 1; i <= 9; i++) {
            string s;
            cin >> s;
            for(int j = 1; j <= 9; j++) {
                sudoku[i][j] = s[j-1];
                if(sudoku[i][j] != '0') {
                    int num = sudoku[i][j] - '0';
                    row[i][num] = 1;
                    col[j][num] = 1;
                    box[(i - 1) / 3 * 3 + (j - 1) / 3 + 1][num] = 1;
                }
            }
        }
        dfs();
        n--;
    }
    return 0;
}