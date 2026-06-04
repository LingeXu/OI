#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#define N 1510
#define M 1510
using namespace std;
int n,m;
bool ok;
int dx[4]={-1,0,0,1},dy[4]={0,-1,1,0};
bool vis[N][M];
char sign[N][M];
struct position{
    int x,y;
}last[N][M];
void dfs(int x,int y){
    if(ok)  return;
    int rx=(x%n+n)%n,ry=(y%m+m)%m;
    if(sign[rx][ry]=='#')
        return;
    if(!vis[rx][ry]){
        last[rx][ry]={x,y};
        vis[rx][ry]=true;
    }
    else{
        if(x!=last[rx][ry].x||y!=last[rx][ry].y)
            ok=true;
        return;
    }
    for(int i=0;i<4;i++)
        dfs(x+dx[i],y+dy[i]);
}
int main(){
    while(cin>>n>>m){
        int stx,sty;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>sign[i][j];
                if(sign[i][j]=='S')
                    stx=i,sty=j;
            }
        }
        ok=false;
        memset(vis,0,sizeof(vis));
        dfs(stx,sty);
        cout<<(ok?"Yes":"No")<<'\n';
    }
    return 0;
}