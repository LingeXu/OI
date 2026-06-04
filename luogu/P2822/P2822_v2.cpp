#include<iostream>

#define N 2001
#define M 2001

using namespace std;

int t,k;
int C[N][M];
long long s[N][M];

int main(){
    cin>>t>>k;

    for(int i=0;i<N;i++)
    {
        C[i][0]=C[i][i]=1%k;

        for(int j=1;j<i;j++)
            C[i][j]=(C[i-1][j]+C[i-1][j-1])%k;
    }

    for(int i=1;i<N;i++)
    {
        for(int j=1;j<N;j++)
        {
            if(i>=j)
                s[i][j]=s[i-1][j]-s[i-1][j-1]+s[i][j-1]+(C[i][j]==0);

            else
                s[i][j]=s[i][i];
        }
    }

    /*for(int i=0;i<N;i++)
        for(int j=i+1;j<M;j++)
            s[i][j]=s[i][i];*/

    while(t>0){
        int n,m;
        cin>>n>>m;

        if(k==1)  
        {
            printf("%d\n",(n+1)*(m+1));
            break;
        } 

        printf("%lld\n",s[n][m]);

        t--;
    }

    return 0;
}