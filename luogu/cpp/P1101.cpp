#include<iostream>
#include<cstring>
#define N 110
using namespace std;
int n;
char c[N][N];
bool notchange[N][N], final[N][N];

char word[8] = {' ','y','i','z','h','o','n','g'};
int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
void dfs(int u, int x, int y,int dir){
    if(u == 7){
        notchange[x][y] = 1;
        return;
    };
    if(x + dx[dir] >= 1 && x + dx[dir] <= n && y + dy[dir] >= 1 && y + dy[dir] <= n && c[x + dx[dir]][y +dy[dir]] == word[u + 1]){
        dfs(u + 1, x + dx[dir], y + dy[dir], dir);
        if(notchange[x + dx[dir]][y + dy[dir]])
            notchange[x][y] = 1;
    }
}

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            cin >> c[i][j];
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(c[i][j] == 'y'){
                for(int k = 0; k < 8; k++){
                    memset(notchange, 0, sizeof(notchange));
                    dfs(1, i, j, k);
                    for(int x = 1; x <= n; x++)
                        for(int y = 1; y <= n; y++)
                            if(!final[x][y])
                                final[x][y] = notchange[x][y];
                }
            }
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++)
            cout << (final[i][j] == 0 ? '*' : c[i][j]);
        cout << '\n';
    }
    return 0;
}