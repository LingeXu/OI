#include<iostream>
#include<algorithm>
#define N 1 << 15
using namespace std;
int MAXX, MAXY;
char c[N][N];
void draw(int x,int offset_x, int offset_y){
    if(x == 1){
        c[offset_x][offset_y + MAXY / 2 - 1] = '/';
        c[offset_x][offset_y + MAXY / 2] = '\\';
        c[offset_x + 1][offset_y + MAXY / 2 - 2] = '/';
        c[offset_x + 1][offset_y + MAXY / 2 - 1] = '_';
        c[offset_x + 1][offset_y + MAXY / 2 ] = '_';
        c[offset_x + 1][offset_y + MAXY / 2 + 1] = '\\';
        return;
    }
    int add = 1 << (x - 1);
    draw(x - 1, offset_x, offset_y);
    draw(x - 1, offset_x + add, offset_y - add);
    draw(x - 1, offset_x + add, offset_y + add);
}
int main(){
    int n;
    cin >> n;
    MAXX = 1 << n;
    MAXY = 1 << (n + 1); 
    for(int i = 0; i < MAXX; i++)
        for(int j = 0; j < MAXY; j++)
            c[i][j] = ' ';
        
    draw(n, 0, 0);
    for(int i = 0; i < MAXX; i++){
        for(int j = 0; j < MAXY; j++)
            cout << c[i][j];
        cout << '\n';
    }
    return 0;
}