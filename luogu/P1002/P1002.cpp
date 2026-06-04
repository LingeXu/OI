#include<iostream>
#include<cstring>
#define N 25
#define M 25
typedef long long ll;
using namespace std;
int a, b, c, d;
char dp[N][M];
ll vis[N][M];
ll GetSum(int x, int y){
    if(x < 0 || x > a || y < 0 || y > b)    return 0;
    if(vis[x][y] != -1)
        return vis[x][y];   
    if(x == 0 && y == 0)    return vis[0][0] = 1;
    if(dp[x][y] == '*')   return vis[x][y] = 0;
    return vis[x][y] = GetSum(x - 1, y) + GetSum(x, y - 1);
}
int main(){
    cin >> a >> b >> c >> d;
    dp[c][d] = '*';
    if(c - 2 >= 0 && d - 1 >= 0)
        dp[c - 2][d - 1] = '*';
    if(c - 1 >= 0 && d - 2 >= 0)
        dp[c - 1][d - 2] = '*';
    if(c + 1 <= a && d - 2 >= 0)
        dp[c + 1][d - 2] = '*';
    if(c + 2 <= a && d - 1 >= 0)
        dp[c + 2][d - 1] = '*';
    if(c - 2 >= 0 && d + 1 <= b)
        dp[c - 2][d + 1] = '*';
    if(c - 1 >= 0 && d + 2 <= b)
        dp[c - 1][d + 2] = '*';
    if(c + 1 <= a && d + 2 <= b)
        dp[c + 1][d + 2] = '*';
    if(c + 2 <= a && d + 1 <= b)
        dp[c + 2][d + 1] = '*';
    memset(vis, -1, sizeof(vis));
    cout << GetSum(a, b);
    return 0;
}