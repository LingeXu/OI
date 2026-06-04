#include<iostream>
#include<algorithm>

#define N 1001

using namespace std;

struct mooncake{
    int stock;
    double sum_price,single_price;
}m[N];

bool cmp(mooncake x,mooncake y){
    return x.single_price>y.single_price;
}

int main(){
    int n,d;
    cin>>n>>d;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        m[i].stock=x;
    }
    for(int i=1;i<=n;i++){
        double x;
        cin>>x;
        m[i].sum_price=x;
        m[i].single_price=m[i].sum_price/(m[i].stock*1.00);
    }

    sort(m+1,m+1+n,cmp);

    if(d<=0){
        cout<<"0.00";
        return 0;
    }    

    int now=1;
    double ans=0;
    while(1){
        int mins=min(d,m[now].stock);
        ans+=1.00*mins*m[now].single_price;
        d-=mins;
        if(d==0)    break;
        if(now<n)
            now++;
        else if(now==n)    break;
    }

    printf("%.2f",ans);
    return 0;
}