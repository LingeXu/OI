#include<iostream>
#include<cmath>

using namespace std;

typedef long long ll;

ll a,b,p;

ll fast_pow(ll a,ll b,ll p){
    ll ans=1;

    while(b){
        if(b&1)
            ans=ans*a%p;

        a=a*a%p;
        b>>=1;
    }

    return ans;
}

int main(){
    cin>>a>>b>>p;

    //cout<<fast_pow(a,b,p)<<endl;

    printf("%lld^%lld mod %lld=%lld",a,b,p,fast_pow(a,b,p));

    return 0;
}