#include<iostream>

using namespace std;

int t,k;

int modk(int n,int m){
    if(m==0||n==m)
        return 1%k;

    return (modk(n-1,m)+modk(n-1,m-1))%k;
}

int main(){
    cin>>t>>k;

    while(t>0){
        int n,m;
        cin>>n>>m;

        int cnt=0;

        for(int i=0;i<=n;i++)
            for(int j=0;j<=min(i,m);j++)
                if(modk(i,j)==0)
                    cnt++;

        printf("%d\n",cnt);

        t--;
    }

    return 0;
}