#include<iostream>

#define NA 201
#define NB 201

using namespace std;

int n,na,nb;
int a[NA],b[NB];

int result1[5][5]={{0,0,1,1,0},{1,0,0,1,0},{0,1,0,0,1},{0,0,1,0,1},{1,1,0,0,0}};
int result2[5][5]={{0,1,0,0,1},{0,0,1,0,1},{1,0,0,1,0},{1,1,0,0,0},{0,0,1,1,0}};

int main(){
    cin>>n>>na>>nb;

    for(int i=1;i<=na;i++)   cin>>a[i];
    for(int i=1;i<=nb;i++)   cin>>b[i];
    a[0]=a[na],b[0]=b[nb];

    int score1=0,score2=0;
    for(int i=1;i<=n;i++)
    {
        int x=i%na,y=i%nb;
        score1+=result1[a[x]][b[y]];
        score2+=result2[a[x]][b[y]];
    }

    printf("%d %d",score1,score2);

    return 0;
}