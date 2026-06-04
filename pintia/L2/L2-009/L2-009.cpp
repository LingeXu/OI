#include<iostream>

#define N 10001
#define K 21

using namespace std;

struct income{
    int now,in,out,all,num;
    double ans;
}p[N];

bool cmp(income x,income y){
    return (x.ans>y.ans)||(x.ans==y.ans&&x.num>y.num)||(x.ans==y.ans&&x.num==y.num&&x.now<y.now);
}

int main(){
    int n;
    cin>>n;

    for(int i=1;i<=n;i++){
        int x,sum=0;;
        cin>>x;

        for(int j=1;j<=x;j++){
            int a,b;
            cin>>a>>b;
            p[a].in+=b;
            p[a].num++;
            sum+=b;
        }

        p[i].out=sum;
    }

    for(int i=1;i<=n;i++){
        p[i].now=i;
        p[i].all=p[i].in-p[i].out;
        p[i].ans=(double)p[i].all/100.0;
    }  

    sort(p+1,p+n+1,cmp);

    for(int i=1;i<=n;i++)  
        //cout<<p[i].now<<" "<<p[i].all/100<<endl;
        printf("%d %.2f\n",p[i].now,p[i].ans);

    return 0;
}