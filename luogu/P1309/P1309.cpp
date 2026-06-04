#include<iostream>
#include<algorithm>

#define N 100001

using namespace std;

int n,r,q;
int s[2*N],score[2*N];

struct player{
    int id,s,score;
}p[2*N],win[N],lose[N];

bool cmp(player a,player b){
    return a.score>b.score||(a.score==b.score&&a.id<b.id);
}

int main(){
    cin>>n>>r>>q;

    for(int i=1;i<=2*n;i++)
    {
        p[i].id=i;
        cin>>p[i].score;
    }

    for(int i=1;i<=2*n;i++)
        cin>>p[i].s;

    //sort(p+1,p+2*n+1,cmp);

    for(int i=1;i<=r;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(p[2*j-1].s>p[2*j].s)
            {
                p[2*j-1].score++;
                win[j]=p[2*j-1];
                lose[j]=p[2*j];
            }
                
            else
            {
                p[2*j].score++;
                win[j]=p[2*j];
                lose[j]=p[2*j-1];
            }
        }

        int a=1,b=1,c=1;
        while(a<=n&&b<=n){
            if(cmp(win[a],lose[b]))
            {
                p[c]=win[a];
                a++;
            }
            else
            {
                p[c]=lose[b];
                b++;
            }
            c++;
        }

        if(c==2*n+1)    continue;

        for(int k=c;k<=2*n;k++)
        {
            p[k]=lose[b];
            b++;
        }
    }

    cout<<p[q].id<<endl;

    return 0;
}