#include<iostream>
#define N 15
using namespace std;
int n, cnt = 0;
int record[N];
bool vis[N][N];
void dfs(int u){
    memset(vis[u], 0, sizeof(vis[u]));
    for(int i = 1; i <= u - 1; i++){
        vis[u][record[i]] = 1;
        int left = record[i] - u + i, right = record[i] + u - i;
        if(left >= 1)  vis[u][left] = 1;
        if(right <= n)  vis[u][right] = 1;
    }

    for(int i = 1; i <= n; i++){
        if(!vis[u][i]){
            record[u] = i;
            if(u < n)
                dfs(u + 1);
            else{
                bool ok = true;
                for(int i = 1; i <= n; i++){
                    if(record[i] == 0){
                        ok = false;
                        break;
                    }
                }
                if(ok){
                    if(++cnt <= 3){
                        for(int i = 1; i <= n; i++)
                            cout << record[i] << ' ';
                        cout << '\n';
                    }
                }
            }
        }
    }
}
int main(){
    cin >> n;
    dfs(1);
    cout << cnt;
    return 0;
}   