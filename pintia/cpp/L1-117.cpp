#include<iostream>
#include<map>
using namespace std;
map<int, int> mp;
int main() {
    int n;
    cin >> n;
    while(n > 0) {
        int id, record;
        cin >> id >> record;
        if(mp[id] == 0)
            mp[id] = record;
        n--;
    }
    map<int, int>::iterator it;
    int cnt = 0;
    for(it = mp.begin(); it != mp.end(); it++) {
        if(it->second == 0) {
            if(cnt == 0) {
                cout << it->first;
                cnt++;
            }
            else    cout << " " << it->first;
        }
    }
    if(cnt == 0)
        cout << "NONE";
    return 0;
}