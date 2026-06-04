#include<iostream>
#include<stack>
#include<vector>
using namespace std;
stack<char> ans;
vector<char> ReversedAns;
int main(){
    string s;
    int k, del = 0;
    cin >> s >> k;
    auto it = s.begin();
    ans.push(*it);
    it++;
    while(del < k && it != s.end()){
        while(!ans.empty() && *it < ans.top()){
            ans.pop();
            del++;
            if(del == k)
                break;
        }
        ans.push(*it);
        it++;
    }
    while(it != s.end()){
        ans.push(*it);
        it++;
    }
    while(del < k){
        ans.pop();
        del++;
    }
    while(!ans.empty()){
        char c = ans.top();
        ReversedAns.push_back(c);
        ans.pop();
    }
    int start = ReversedAns.size() - 1;
    while(start != 0 && ReversedAns[start] == '0')
        start--;
    for(int i = start; i >= 0; i--)
        cout << ReversedAns[i];
    return 0;
}