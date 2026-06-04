#include<iostream>
#include<unordered_set>
#include<vector>
#include<map>
#define N 50010
using namespace std;
int fa[N];
unordered_set<string> name;
map<int, string> mp1;
map<string, int> mp2;
int find(int x){
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}
void unite(int x, int y){
    int rx = find(x), ry = find(y);
    if(rx != ry)    fa[rx] = ry;
}
int main(){
    string s;
    int id = 0, last_father = -1;
    for(int i = 0; i < N; i++)
        fa[i] = i;
    while(cin >> s && s != "$"){
        string people = s.substr(1);
        if(name.count(people) == 0){
            name.insert(people);
            mp1[name.size()] = people;
            mp2[people] = name.size();
        }
        switch(s[0]){
            case '#': {
                last_father = mp2[people];
                break;
            }
            case '+': {
                unite(mp2[people], last_father);
                break;
            }
            case '?': {
                cout << people << ' ' << mp1[find(mp2[people])] << '\n';
                break;
            }
        }
    }
    return 0;
}