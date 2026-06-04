#include<iostream>

#define N 100001

using namespace std;

struct toy{
    int a;
    string b;
}t[N];

int main(){
    int n,m;
    cin>>n>>m;

    for(int i=0;i<n;i++)
    {
        cin>>t[i].a>>t[i].b;
    }

    int now=0;
    for(int i=0;i<m;i++)
    {
        int c,d;
        cin>>c>>d;

        if(t[now].a==0&&c==0||t[now].a==1&&c==1)
        {
            now=(now-d+n)%n;
        }
        else
        {
            now=(now+d)%n;
        }
    }
    cout<<t[now].b;
    return 0;

}