#include<iostream>

#define N 501

using namespace std;

int now[N][N],ans[N][N];

int main(){
    int n,m;
    cin>>n>>m;

    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++){
            now[i][j]=n*(i-1)+j;
            ans[i][j]=now[i][j];
        }

    /*for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cout<<now[i][j]<<" ";*/
    
    //printf("\n");

    while(m>0){
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        int l=2*c+1;
        if(d==0){   //顺时针
            for(int i=1;i<=2*c+1;i++)
                for(int j=1;j<=2*c+1;j++)
                    ans[a+i-c-1][b+j-c-1]=now[2*c+1-j+a-c][i+b-c-1];
        }    

        else if(d==1){
            for(int i=1;i<=2*c+1;i++)
                for(int j=1;j<=2*c+1;j++)
                    ans[2*c+1-j+a-c][i+b-c-1]=now[a+i-c-1][b+j-c-1];
        }

        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                now[i][j]=ans[i][j];

        m--;
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<ans[i][j]<<" ";
        }
        printf("\n");
    }

    return 0;
}