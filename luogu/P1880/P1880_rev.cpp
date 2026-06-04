#include<iostream>
#include<cstring>

#define N 101

using namespace std;

int main(){
    int n;
    cin>>n;

    int a[2*N];
    for(int i=0;i<n;i++)    cin>>a[i];

    for(int i=n;i<2*n;i++)
    {
        a[i]=a[i-n];
    }

    int dp1[2*N][2*N],dp2[2*N][2*N];
    memset(dp1,0,sizeof(dp1));
    memset(dp2,0x3f,sizeof(dp2));

    for(int i=0;i<2*n;i++)    dp2[i][i]=0;

    for(int len=2;len<=n;len++)
    {
        for(int i=0;i<=2*n-len;i++)
        {
            int j=i+len-1;

            int sum=0;

            for(int now=i;now<=j;now++)
            {
                sum+=a[now];
            }

            for(int k=i;k<j;k++)
            {
                dp1[i][j]=max(dp1[i][j],dp1[i][k]+dp1[k+1][j]+sum);
                dp2[i][j]=min(dp2[i][j],dp2[i][k]+dp2[k+1][j]+sum);
            }
            
        }
    }

    int maxval=0,minval=0x3f3f3f3f;
    for(int i=0;i<n;i++)
    {
        if(dp1[i][i+n-1]>maxval)    maxval=dp1[i][i+n-1];
        if(dp2[i][i+n-1]<minval)    minval=dp2[i][i+n-1];
    }

    printf("%d\n", minval);
    printf("%d\n", maxval);

    return 0;
}