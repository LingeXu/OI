#include <iostream>
#define N 110
using namespace std;
int n;
int a[N][N], b[N][N];
void Floyd(){
    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                if(b[i][k] == 1 && b[k][j] == 1)
                    b[i][j] = 1;
}
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> a[i][j];
            b[i][j] = a[i][j];
        }
    }
    Floyd();
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++)
            cout << b[i][j] << ' ';
        cout << '\n';
    }
    return 0;
}