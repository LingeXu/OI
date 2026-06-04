#include<iostream>
using namespace std;
int SumOfInOrder(string preo, string posto) {
    if(preo.empty() && posto.empty())
        return 1;
    if(preo == posto && preo.size() == 1)
        return 1;
    if(preo[0] != posto.back())
        return 0;
    preo = preo.substr(1);
    posto = posto.substr(0, posto.size() - 1);
    //cout << preo << '\n';
    //cout << posto << '\n';
    int sum = 0;
    //sum += 2*SumOfInOrder(preo, posto);
    string preoleft, preoright, postoleft, postoright;
    for(int i = 0; i <= preo.size(); i++) {
        preoleft = preo.substr(0, i);
        preoright = preo.substr(i, preo.size() - i);
        postoleft = posto.substr(0, i);
        postoright = posto.substr(i, posto.size() - i);
        sum += SumOfInOrder(preoleft, postoleft) * SumOfInOrder(preoright, postoright);
        /*cout << sum << '\n';
        cout << preoleft << '\n';
        cout << preoright << '\n';
        cout << postoleft << '\n';
        cout << postoright << '\n';   
        cout<< SumOfInOrder(preoleft, postoleft) << " " << SumOfInOrder(preoright, postoright) << '\n';*/
    }
    return sum;
}
int main() {
    string preorder, postorder;
    cin >> preorder >> postorder;
    cout << SumOfInOrder(preorder, postorder);
    return 0;
}