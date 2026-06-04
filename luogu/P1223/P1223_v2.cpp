#include<iostream>
#include<algorithm>

#define N 1001

using namespace std;

struct people{
    int id,ti;
}p[N];

bool cmp(people a,people b)
{
    return a.ti<b.ti;
}
int main(){
    int n;
    cin>>n;

    for(int i=0;i<n;i++)
    {
        cin>>p[i].ti;
        p[i].id=i+1;
    }

    sort(p,p+n,cmp);

    long long sum=0;

    for(int i=0;i<n;i++)
    {
        cout<<p[i].id<<" ";
        sum+=p[i].ti*(n-i-1);
    }

    cout<<endl;

    printf("%.2f\n",double(sum)/n);
    
    return 0;
}