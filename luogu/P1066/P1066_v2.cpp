#include<iostream>
#include<vector> 

typedef long long ll;

#define N (1<<9)

using namespace std;

ll k,w;
//ll C[N][N];
vector<int> C[N][N];
vector<int> ans={0};

vector<int> add(vector<int> a,vector<int> b){
    vector<int> c;
    int carry=0;

    for(int i=0;i<max(a.size(),b.size())||carry;i++)
    {
        if(i<a.size())  carry+=a[i];
        if(i<b.size())  carry+=b[i];
        c.push_back(carry%10);
        carry/=10;
    }

    return c;
}

int main(){
    scanf("%lld%lld",&k,&w);

    for(int i=0;i<(1<<k);i++)
    {
        C[i][0]=C[i][i]={1};

        for(int j=1;j<i;j++)
            C[i][j]=add(C[i-1][j-1],C[i-1][j]);
    }

    ll rem=w%k,len=w/k;

    if(rem!=0)
    {
        for(int i=2;i<=len;i++)
            if((1<<k)-1>=i)
                ans=add(ans,C[(1<<k)-1][i]);

        //ans+=((1<<rem)-1)*C[(1<<k)-(1<<rem)][len];

        for(int i=1;i<(1<<rem);i++)
            if((1<<k)-1-i>=len)
                ans=add(ans,C[(1<<k)-1-i][len]);
    }

    else
        for(int i=2;i<=len;i++)
            if((1<<k)-1>=i)
                ans=add(ans,C[(1<<k)-1][i]);

    for(int i=ans.size()-1;i>=0;i--)
        printf("%d",ans[i]);

    return 0;
}