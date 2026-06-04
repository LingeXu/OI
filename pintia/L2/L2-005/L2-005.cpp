#include<iostream>
#include<set>

#define N 51

using namespace std;

set<int> integers[N];

int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        for(int j=0;j<x;j++){
            int ele;
            cin>>ele;
            integers[i].insert(ele);
        }
    }

    int k;
    cin>>k;
    for(int i=1;i<=k;i++){
        int a,b;
        cin>>a>>b;

        int sum=integers[a].size()+integers[b].size(),inter=0;
        //printf("%d\n",sum);
        for(int x:integers[a])
            inter+=integers[b].count(x);
        //printf("%d\n",inter);
        sum-=inter;
        double ans=1.00*inter/sum*100;
        printf("%.2f%%\n",ans);
    }

    return 0;
}