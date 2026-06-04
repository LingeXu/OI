#include<iostream>
#include<vector>

using namespace std;

int main(){
    int n,m;
    cin>>n>>m;

    vector<int> student;

    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        student.push_back(x);
    } 
    
    for(int i=0;i<m;i++){
        int x;
        cin>>x;

        cout<<student[x-1]<<endl;
    }

    return 0;
}