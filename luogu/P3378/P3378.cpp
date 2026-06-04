#include<iostream>
#include<queue>

#define N 1000001

using namespace std;

int a[N];
priority_queue <int,vector<int>,greater<int> > s;

int main(){
    int n;
    scanf("%d",&n);

    int j=0;

    for(int i=0;i<n;i++)
    {
        int m;
        scanf("%d",&m);
        if(m==1)
        {

            int x;
            scanf("%d",&x);
            s.push(x);
        }

        else if(m==2)
        {
            a[j]=s.top();
            j++;
        }

        else if(m==3)
            s.pop();
    }

    for(int i=0;i<j;i++)
    {
        printf("%d\n",a[i]);
    }

    return 0;
}