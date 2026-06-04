#include<iostream>
#include<vector>

using namespace std;

int main(){
    int n;
    cin>>n;

    vector<int> a(n+1);

    for(int i=0;i<=n;i++)   cin>>a[i];

    for(int i=0;i<=n;i++)
        if(a[i]!=0){
            if(a[i]>0&&i!=0)
                cout<<'+';
            else if(a[i]<0)
                cout<<'-';

            if(i==n)    cout<<abs(a[i]);
            else if(i==n-1)
                if(abs(a[i])!=1)
                    cout<<abs(a[i])<<'x';
                else    cout<<'x';
            else{
                if(abs(a[i])!=1)
                    cout<<abs(a[i])<<"x^"<<n-i;
                else
                    cout<<"x^"<<n-i;
            }   
        }
            
    return 0;
}