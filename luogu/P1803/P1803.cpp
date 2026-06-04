#include<iostream>

#define N 1000001

using namespace std;

struct ti{
    int begin,end;
}t[N];

bool cmp(ti x,ti y){
    return x.begin<y.begin;
}

int main(){
    int n;
    cin>>n;

    for(int i=0;i<n;i++)    cin>>t[i].begin>>t[i].end;

    sort(t,t+n,cmp);
    
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(t[i].end>=t[j].end)
            {
                t[i].begin=t[j].begin;
                t[i].end=t[j].end;
            }
        }
    }

    sort(t,t+n,cmp);

    int ans=1;

    int i=1;
    int now=0;
    while(i<n){
        if(t[i].begin>=t[now].end)
        {
            ans++;
            now=i;
        }
        i++;
    }
    
    printf("%d\n",ans);

    return 0;
}