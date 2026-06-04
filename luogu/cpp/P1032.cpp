#include<iostream>
#include<vector>
#include<queue>
#include<map>
using namespace std;
string a, b;
struct change{
    string from, to;
};
vector<change> c;
map<string, bool> mp1;
map<string, int> mp2;
void bfs(){
    queue<string> q;
    q.push(a);
    mp1[a] = true;
    mp2[a] = 0;
    while(!q.empty()){
        string x = q.front();
        if(x == b){
            cout << mp2[b];
            return;
        }
        q.pop();
        for(int i = 0; i < c.size(); i++){
            int pos = 0;
            while((pos = x.find(c[i].from, pos)) != string::npos){
                string newx = x.substr(0, pos) + c[i].to + x.substr(pos + c[i].from.size());
                if(!mp1[newx]){
                    mp1[newx] = true;
                    mp2[newx] = mp2[x] + 1;
                    if(mp2[newx] > 10){
                        cout << "NO ANSWER!";
                        return;
                    }
                    q.push(newx);
                }
                pos++;
            }
        }
    }
    cout << "NO ANSWER!";
}
int main(){
    cin >> a >> b;
    string s1, s2;
    while(cin >> s1 >> s2)
        c.push_back({s1, s2});
    bfs();
    return 0;
}