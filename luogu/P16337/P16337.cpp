#include<iostream>
#include<algorithm>

using namespace std;

int main(){
    int t;
    cin>>t;

    while(t>0){
        int n,m,k;
        cin>>n>>m>>k;

        while(k>0){
            n=n and max(n-m,0);
            k--;
        }

        cout<<n<<'\n';

        t--;
    }

    cout<<9 and 8<<'\n';

    return 0;
}