#include<iostream>
#include<cmath>

#define B 31

using namespace std;

long long a,b,q;
long long mod[B];

int main(){
    cin>>a>>b>>q;

    mod[0]=a%q;

    long long remain=b;
    long long ans=1;

    for(long long i=1;i<=(int)log2(b);i++)
    {
        mod[i]=(mod[i-1]*mod[i-1])%q;
        //cout<<i<<" "<<mod[i]<<endl;
    }

    while(remain>0){
        long long c=log2(remain);
        remain-=(1<<c);
        ans=(ans*mod[c])%q;
    }

    //cout<<ans<<endl;

    printf("%lld^%lld mod %lld=%lld\n",a,b,q,ans);

    return 0;
}