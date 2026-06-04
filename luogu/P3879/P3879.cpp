#include<iostream>
#include<set>
#define N 1010
using namespace std;
set<string> s[N];
int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int l;
        cin >> l;
        for(int j = 1; j <= l; j++){
            string word;
            cin >> word;
            s[i].insert(word);
        }
    }
    int m;
    cin >> m;
    for(int i = 1; i <= m; i++){
        string inquire;
        cin >> inquire;
        bool found = false;
        for(int j = 0; j < n; j++){
            if(s[j].count(inquire) == 1){
                if(!found){
                    cout << j + 1;
                    found = true;
                }
                else if(found)
                    cout << ' ' << j + 1;
            }
        }
        cout << '\n';
    }
    return 0;
}