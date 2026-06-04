#include<iostream>
#include<set>

using namespace std;

set<int> tracks;

int main(){
    int n;
    cin>>n;

    for(int i=1;i<=n;i++){
        int x;
        cin>>x;

        set<int>::iterator it=tracks.upper_bound(x);
        if(it!=tracks.end())
            tracks.erase(it);
        tracks.insert(x); 
    }

    cout<<tracks.size();
    return 0;
}