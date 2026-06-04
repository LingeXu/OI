#include<iostream>
using namespace std;
#define N 15
int length[N], height[N];
char c[100000][100000];
struct mark{
    int x, y;
    char sign;
}w[100000][100000];
int main(){
    int m, n;
    cin >> m >> n;
    length[2] = 5, height[2] = 3;
    length[1] = height[1] = 1;
    for(int i = 3; i <= m; i++){
        length[i] = length[i - 1] * 2 + 1;
        height[i] = height[i - 1] * 2;
    }
    for(int i = 0; i < height[m]; i++)
        for(int j = 0; j < length[m]; j++)
            c[i][j] = ' ';
    for(int i = 2; i <= m; i++){
        for(int j = height[i] - 1; j <= length[m] - height[i]; ){
            c[height[m] - height[i]][j] = 'o';
            j += length[i] + 1;
        }
    }
    int cnt = 0, last = -2;
    while(last < length[m]){
        if(cnt % 2 == 0){
            c[height[m] - 1][last + 2] = 'o';
            last += 2;
            cnt++;
        }
        else{
            c[height[m] - 1][last + 4] = 'o';
            last += 4;
            cnt++;
        }
    }
    for(int i = 0; i < height[m]; i++){
        for(int j = 0; j < length[m]; j++){
            if(c[i][j] == 'o'){
                c[i + 1][j - 1] = '/';
                c[i + 1][j + 1] = '\\'; 
                continue;
            }
            if(c[i][j] == '/' && c[i + 1][j - 1] != 'o'){
                c[i + 1][j - 1] = '/';
                continue;
            }
            if(c[i][j] == '\\' && c[i + 1][j + 1] != 'o'){
                c[i + 1][j + 1] = '\\';
                continue;
            }          
        }
    }

    /*for(int i = 1; i <= m; i++){
        for(int j = 1; j <= (1 << (i - 1)); j++){
            w[i][j].x = height[m] - height[m - i + 1];
            if(i != m)
                w[i][j].y = height[m - i + 1] - 1 + (j - 1) * (length[m - i + 1] + 1);
            else
                w[i][j].y = (j % 2 == 0 ? (3 * j - 2) : (3 * j - 3));
            w[i][j].sign = c[w[i][j].x][w[i][j].y];
        }
    }

    for(int i = 1; i <= n; i++){
        int row, col;
        cin >> row >> col;
        for(int j = w[row][col].x; j < height[m]; j++)
            for(int k = 2 * w[row][col].y - w[m][col * (1 << (m - row))].y; k <= w[m][col * (1 << (m - row))].y; k++)
                c[j][k] = ' ';
    }*/

    /*for(int i = 1; i <= n; i++){
        int row, col;
        cin >> row >> col;
        for(int j = height[m] - height[m - row + 1]; j < height[m]; j++)
            for(int k = col * (1 << (m - row)) * 3 - (col * (1 << (m - row))) % 2 - 2 - (length[m - row + 1] - 1); k <= col * (1 << (m - row)) * 3 - (col * (1 << (m - row))) % 2 - 2; k++)
                c[j][k] = ' ';
    }*/

    for(int i = 0; i < height[m]; i++){
        for(int j = 0; j < length[m]; j++){
            cout << c[i][j];
        }
        cout << '\n';
    }

    return 0;
}
