#include<iostream>
#include<vector>
#include<cmath>
#include<cstring>
#include<algorithm>
typedef long long ll;
using namespace std;
int main(){
    int m, n;
    ll sum = 0;
    cin >> m >> n;
    vector<int> school(m), student(n);
    for(int i = 0; i < m; i++)  cin >> school[i];
    for(int i = 0; i < n; i++)  cin >> student[i];
    sort(school.begin(), school.end());
    sort(student.begin(), student.end());
    int last = 0;
    for(int i = 0; i < n; i++){
        int left = last, right = m - 1;
        while(right - left > 1){
            if(student[i] < school[left]){
                sum += (school[left] - student[i]);
                last = left;
                //cout << sum << ' ';
                break;
            }
            if(student[i] > school[right]){
                sum += (student[i] - school[right]);
                last = right;
                //cout << sum << ' ';
                break;
            }
            int mid = (left + right) / 2;
            if(student[i] == school[mid]){
                last = mid;
                break;
            }
            if(student[i] > school[mid]){
                left = mid;
                continue;
            }
            if(student[i] < school[mid]){
                right = mid;
                continue;
            }
        }
        if(left == right)
            sum += 1LL * fabs(student[i] - school[left]);
        if(left + 1 ==right)
            sum += 1LL * min(fabs(student[i] - school[left]), fabs(student[i] - school[right]));
        last = left;
        //cout << sum << ' ';
    }
    cout << sum;
    return 0;
}