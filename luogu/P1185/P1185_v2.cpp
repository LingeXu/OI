#ifdef LOCAL
#define debug(x)    cout << '[' << __LINE__ << ']' << ' ' << #x << " = " << x;
#else
#define debug(x)
#endif
#include<iostream>
#define M 2000
using namespace std;

int m, n;
char sign[M][M];
bool del[M][M];
int height[M], width[M], branch[M];

void draw(int row, int col){
    if(row == m){
        sign[height[m] - 1][col * 3 - 2 - col % 2] = 'o';
        return;
    }
    int x = height[m] - height[m - row + 1];
    int y = (width[m - row + 1] + 1) / 2 - 1 + (col - 1) * (width[m - row + 1] + 1);
    sign[x][y] = 'o';
    if(!del[row + 1][2 * col - 1]){
        for(int i = 1; i <= branch[m - row + 1]; i++)
            sign[x + i][y - i] = '/';
        draw(row + 1, 2 * col - 1);
    }
    if(!del[row + 1][2 * col]){
        for(int i = 1; i <= branch[m - row + 1]; i++)
            sign[x + i][y + i] = '\\';
        draw(row + 1, 2 * col);
    }
}

int main(){
    cin >> m >> n;
    for(int i = 1; i <= n; i++){
        int row, col;
        cin >> row >> col;
        del[row][col] = true;
    }
    width[1] = 1;
    width[2] = 5;
    for(int i = 3; i <= m; i++)
        width[i] = width[i - 1] * 2 + 1;
    for(int i = 1; i <= m; i++)
        height[i] = (width[i] + 1) / 2;
    branch[1] = 0;
    for(int i = 2; i <= m; i++)
        branch[i] = height[i] - height[i - 1] - 1;
    for(int i = 0; i < height[m]; i++)
        for(int j = 0; j < width[m]; j++)
            sign[i][j] = ' ';
    draw(1,1);
    for(int i = 0; i < height[m]; i++){
        for(int j = 0; j < width[m]; j++)
            cout << sign[i][j];
        cout << '\n';
    }
    return 0;
}