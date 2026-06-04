#include<iostream>
#include<cmath>
#include<cstring>

#define N 100000001

using namespace std;

int n,q;
int ranking[N];

bool isPrime(int x){
    if(x==1)    return  0;
    if(x==2)    return 1;

    for(int i=2;i<=sqrt(x);i++)
        if(x%i==0)
            return 0;

    return 1;
}

int main(){
    cin>>n>>q;

    memset(ranking,0,sizeof(ranking));

    for(int i=1;i<=n;i++)
        ranking[i]=ranking[i-1]+isPrime(i);

    int now=0;

    for(int i=1;i<=q;i++)
    {
        int x;
        cin>>x;

        while(ranking[now]<x){
            now++;
        }

        cout<<now<<endl;
    }

    return 0;
}