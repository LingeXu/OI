#include<iostream>

#define N 101
#define M 101

using namespace std;

int main(){
    int n,m;
    cin>>n>>m;

    char c[N][M];

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>c[i][j];
        }
    }

    int cnt=0;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(c[i][j]=='*')  printf("*");
            else
            {
                if(i-1>=0&&j-1>=0&&c[i-1][j-1]=='*')    cnt++;
                if(i-1>=0&&c[i-1][j]=='*')    cnt++;
                if(i-1>=0&&j+1<m&&c[i-1][j+1]=='*')    cnt++;
                if(j-1>=0&&c[i][j-1]=='*')   cnt++;
                if(j+1<m&&c[i][j+1]=='*')   cnt++;
                if(i+1<n&&j-1>=0&&c[i+1][j-1]=='*') cnt++;
                if(i+1<n&&c[i+1][j]=='*')   cnt++;
                if(i+1<n&&j+1<m&&c[i+1][j+1]=='*')  cnt++;

                printf("%d",cnt);
                cnt=0;
            }
        }
        printf("\n");
    }

    return 0;
}