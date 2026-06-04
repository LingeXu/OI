#include<iostream>
#include<vector>

#define N 100000001

using namespace std;

int n,q;

vector<int> prime;
bool isPrime[N];

void euler(int n){
    for(int i=2;i<=n;i++)
    {
        if(!isPrime[i])
            prime.push_back(i);

        for(int j=0;j<prime.size();j++)
        {
            if(i*prime[j]>n)
                break;

            isPrime[i*prime[j]]=true;

            if(i%prime[j]==0)
                break;
        }
    }
}

int main(){
    cin>>n>>q;

    euler(n);

    for(int i=1;i<=q;i++)
    {
        int x;
        cin>>x;

        cout<<prime[x-1]<<endl;
    }

    return 0;
}