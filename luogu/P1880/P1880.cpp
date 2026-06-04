#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#define M 201
const int INF = 0x3f3f3f3f;
using namespace std;

int main(){
    int n;
    scanf("%d",&n);
    int a[M];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        a[i+n]=a[i];
    }

    int dp1[M][M],dp2[M][M];
    memset(dp1,0,sizeof(dp1));
    memset(dp2,0x3f,sizeof(dp2));

    for(int i=0;i<2*n;i++)
    {
        dp2[i][i]=0;
    }
    for(int i=0;i<n;i++)
    {
        for(int len=2;len<=n;len++)
        {
            int sum=0;
            for(int j=i;j<i+len;j++)
            {
                sum+=a[j];
            }
            for(int k=i;k<i+len-1;k++)
            {
                dp1[i][i+len-1]=max(dp1[i][i+len-1],dp1[i][k]+dp1[k+1][i+len-1]+sum);
                dp2[i][i+len-1]=min(dp2[i][i+len-1],dp2[i][k]+dp2[k+1][i+len-1]+sum);
            }
        }
    }
    int MAX=0,MIN=INF;
    for(int i=0;i<n;i++)
    {
        MAX=max(MAX,dp1[i][i+n-1]);
        MIN=min(MIN,dp2[i][i+n-1]);
    }
    printf("%d",MIN);
    printf("%d\n",MAX);
    
    return 0;
}