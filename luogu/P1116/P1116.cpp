#include<iostream>

#define N 1001

using namespace std;

int n;
int a[N];

int main(){
    cin>>n;

    for(int i=0;i<n;i++)    cin>>a[i];

    int cnt=0;

    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(a[i]>a[j])  
            {
                swap(a[i],a[j]);
                cnt++;
            } 
        }
    }

    cout<<cnt<<endl;
}