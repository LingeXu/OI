#include<iostream>
#include<cstring>
#include<algorithm>
#define N 25
using namespace std;
int n, ans = 0;
int used[N];
string word[N];
int check(string a, string b){
    int Length = min(a.size(), b.size());
    for(int i = 1; i < Length; i++)
        if(a.substr(a.size() - i) == b.substr(0, i))
            return i;
    return 0;
}
void dfs(string s, int Length){
    ans = max(ans, Length);
    for(int i = 0; i < n; i++){
        int coincide = check(s, word[i]);
        if(coincide != 0 && used[i] < 2){
            used[i]++;
            dfs(word[i], Length + word[i].size() - coincide);
            used[i]--;
        }
    }
}
int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> word[i];
    char c;
    cin >> c;
    for(int i = 0; i < n; i++){
        if(word[i][0] == c){
            memset(used, 0, sizeof(used));
            used[i]++;
            dfs(word[i], word[i].size());
        }
    }
    cout << ans;
    return 0;
}