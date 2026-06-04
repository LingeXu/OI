#include<iostream>

using namespace std;

int main(){
    int t;
    cin>>t;
    int n,m,k;
    while(t>0){
        cin>>n>>m>>k;

        if(m==0){
            cout<<n<<"\n";
            t--;
            continue;
        }

        int modk=n%k;
        long long ans=modk+m-1;
        if(modk==0||ans>=k){
            cout<<0<<"\n";
        }

        else{
            cout<<modk<<"\n";
        }

        t--;
    }

    return 0;
}