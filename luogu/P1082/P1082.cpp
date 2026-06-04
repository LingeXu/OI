#include<iostream>

using namespace std;

typedef long long ll;

ll a,b;


ll exgcd(ll a, ll b) {

    if(b==1)
        return 1;
    
    ll d = (1-b*exgcd(b, a % b))/(a%b);
   
    d=(d%b+b)%b;

    return d;
}

void exgcd(ll a,ll b,ll &x,ll &y){

}

int main(){
    cin>>a>>b;

    printf("%lld",exgcd(a,b));

    return 0;
}