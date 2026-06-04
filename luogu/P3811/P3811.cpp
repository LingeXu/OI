#include<iostream>
#include<cstring>

#define N 3000001

typedef long long ll;

using namespace std;

ll n,p,ans[N];

int main(){
    cin>>n>>p;

    memset(ans,0,sizeof(ans));

    ans[1]=1;

    for(int i=2;i<=n;i++)
        ans[i]=(-ans[p%i]*(p/i)%p+p)%p;

    for(int i=1;i<=n;i++)
        printf("%lld\n",ans[i]);

    return 0;
}