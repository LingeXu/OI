#include<iostream>
#include<vector>

using namespace std;

int main(){
    int n,q;
    cin>>n>>q;

    vector< vector<int> > locker(n);
    for(int i=1;i<=q;i++){
        int x;
        cin>>x;

        if(x==1){
            int a,b,c;
            cin>>a>>b>>c;

            if(locker[a-1].size()<b)
                locker[a-1].resize(b);

            locker[a-1][b-1]=c;
        }

        else if(x==2){
            int a,b;
            cin>>a>>b;

            cout<<locker[a-1][b-1]<<endl;
        }
    }

    return 0;
}