#include<iostream>
#include<set>
using namespace std;
set< pair<string, int> > s;
set<string> n;
int main(){
    int Q;
    cin >> Q;
    while(Q > 0){
        int op;
        cin >> op;
        if(op == 1){
            string name;
            int score;
            cin >> name >> score;
            if(n.count(name) == 0){
                n.insert(name);
                s.insert({name, score});
                cout << "OK" << '\n';
                Q--;
                continue;
            }
            else if(n.count(name) == 1){
                auto it = s.lower_bound({name, 1e-9});
                s.erase(it);
                s.insert({name, score});
                cout << "OK" << '\n';
                Q--;
                continue;
            }         
        }
        else if(op == 2){
            string name;
            cin >> name;
            if(n.count(name) == 0){
                cout << "Not found" << '\n';
                Q--;
                continue;
            }
            else if(n.count(name) == 1){
                auto it = s.lower_bound({name, 1e-9});
                cout << it->second << '\n';
                Q--;
                continue;
            }
        }
        else if(op == 3){
            string name;
            cin >> name;
            if(n.count(name) == 0){
                cout << "Not found" << '\n';
                Q--;
                continue;
            }
            else if(n.count(name) == 1){
                auto it = s.lower_bound({name, 1e-9});
                s.erase(it);
                n.erase(name);
                cout << "Deleted successfully" << '\n';
                Q--;
                continue;
            }
        }
        else if(op == 4){
            cout << n.size() << '\n';
            Q--;
            continue;
        }
    }
    return 0;
}