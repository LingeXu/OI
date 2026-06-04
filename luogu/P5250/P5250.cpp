#include<iostream>
#include<set>
#include<functional>
using namespace std;
set< int, less<int> > s;
int main(){
    int m;
    cin >> m;
    while(m > 0){
        int op, Length;
        cin >> op >> Length;
        if(op == 1){
            if(s.count(Length) == 1){
                cout << "Already Exist" << '\n';
                m--;
                continue;
            }
            else if(s.count(Length) == 0){
                s.insert(Length);
                m--;
                continue;
            }
        }
        else if(op == 2){   
            if(s.empty()){
                cout << "Empty" << '\n';
                m--;
                continue;
            }
            /*int cnt = 0;
            while(s.count(Length) == 0){
                cnt % 2 == 0 ? Length -= (1 << cnt) : Length += (1 << cnt);
                cnt++;
            }
            cout << Length << '\n';
            s.erase(Length);
            m--;
            continue;*/
            auto successor = s.lower_bound(Length);
            auto precursor = prev(successor);
            if(successor == s.end()){
                cout <<  *precursor << '\n';
                s.erase(precursor);
                m--;
                continue;
            }
            if(successor == s.begin()){
                cout <<  *successor << '\n';
                s.erase(successor);
                m--;
                continue;
            }
            cout << ((Length - *precursor <= *successor - Length) ? *precursor : *successor) << '\n';
            s.erase((Length - *precursor <= *successor - Length) ? precursor : successor);
            m--;
            continue;
        }   
    }
    return 0;
}