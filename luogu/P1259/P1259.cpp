#include<iostream>
#define N 110
using namespace std;
int n;
void deal(int x){
    if(x == 4){
        int remain = n - 4;
        cout << "oooo****--";
        for(int i = 1; i <= remain; i++)
            cout << "o*";
        cout << '\n';
        cout << "ooo--***o*";
        for(int i = 1; i <= remain; i++)
            cout << "o*";
        cout << '\n';
        cout << "ooo*o**--*";
        for(int i = 1; i <= remain; i++)
            cout << "o*";
        cout << '\n';
        cout << "o--*o**oo*";
        for(int i = 1; i <= remain; i++)
            cout << "o*";
        cout << '\n';
        cout << "o*o*o*--o*";
        for(int i = 1; i <= remain; i++)
            cout << "o*";
        cout << '\n';
        cout << "--o*o*o*o*";
        for(int i = 1; i <= remain; i++)
            cout << "o*";
        cout << '\n';
        return;
    }
    for(int i = 1; i <= x; i++)
        cout<< 'o';
    for(int i = 1; i <= x; i++)
        cout<< '*';
    cout << "--";
    for(int i = 1; i <= n - x; i++)
        cout << "o*";
    cout << '\n';
    for(int i = 1; i <= x - 1; i++)
        cout << 'o';
    cout << "--";
    for(int i = 1; i <= x - 1; i++)
        cout << '*';
    for(int i = 1; i <= n - x + 1; i++)
        cout << "o*";
    cout << '\n';
    deal(x - 1);
}
int main(){
    cin >> n;
    deal(n);
    return 0;
}