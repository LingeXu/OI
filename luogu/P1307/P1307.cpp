#include<iostream>

using namespace std;

int main(){
    long long n;
    cin>>n;

    if(n==0)  
    {
        cout<<"0";
        return 0;
    }  

    while(n%10==0) n/=10;

    if(n<0) 
    {
        cout<<"-";
        n*=-1;
    }

    while(n!=0){
        printf("%lld",n%10);
        n/=10;
    }

    return 0;
}