#include<iostream>

#define N (1<<9)

typedef long long ll;

using namespace std;

int k,w;

/*int C(int x,int y){
    if(y==0||x==y)    return 1;

    return C(x-1,y)+C(x-1,y-1);
}*/

ll C[N][N];

int main(){
    cin>>k>>w;

    int a=w%k,b=w/k;

    for(int i=0;i<=(1<<k)-1;i++)
        C[i][0]=1;

    for(int i=1;i<=(1<<k);i++)
    {
        for(int j=1;j<=i;j++)
            C[i][j]=C[i-1][j]+C[i-1][j-1];
    }

    /*for(int i=0;i<=5;i++)
        for(int j=0;j<=i;j++)
            cout<<C[i][j]<<endl;*/

    ll ans=0;

    if(a!=0)
        for(int i=0;i<=(1<<a)-1;i++)
            if(b<=(1<<k)-i-1)
                ans+=C[(1<<k)-i-1][b];

    if(a==0)
        if((1<<k)-1>=b)
            ans+=C[(1<<k)-1][b];

    printf("%lld\n",ans);

    return 0;
}