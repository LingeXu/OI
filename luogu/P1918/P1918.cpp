#include<iostream>
#include<set>
using namespace std;
set< pair<int, int> > s;
int main(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        int x;
        cin >> x;
        s.insert(make_pair(x, i));
    }
    int q;
    cin >> q;
    for(int i = 1; i <= q; i++){
        int x;
        cin >> x;
        auto it = s.lower_bound(make_pair(x, 1e-9));
        if(it != s.end() && it->first == x)
            cout << it->second << '\n';
        else    cout << 0 << '\n';
    }
    return 0;
}