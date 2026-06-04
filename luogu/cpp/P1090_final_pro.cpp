#include<iostream>
#include<vector>
#include<queue>

using namespace std;

priority_queue<int,vector<int>,greater<int> > p;

int main(){
    int n;
    scanf("%d",&n);

    for(int i=0;i<n;i++)
    {
        int m;
        scanf("%d",&m);
        p.push(m);
    }

    int sum=0;

    while(p.size()>1)
    {
        int max1=p.top();
        sum+=max1;
        p.pop();

        int max2=p.top();
        sum+=max2;
        p.pop();

        p.push(max1+max2);
    }

    printf("%d",sum);
    return 0;
}