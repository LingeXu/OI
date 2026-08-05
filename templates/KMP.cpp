vector<int> init(const string& pat) {
    int n = pat.size();
    vector<int> res(n + 1);
    res[0] = -1;
    int i = 0, j = -1;
    while(i < n) {
        if(j == -1 || pat[i] == pat[j]) 
            res[++i] = ++j;
        else    j = res[j];
    }
    return res;
}

vector<int> KMP(const string& ob, const string& pat) {
    vector<int> res;
    int n = ob.size(), m = pat.size();
    vector<int> next = init(pat);
    int i = 0, j = 0;
    while(i < n) {
        if(j == -1 || ob[i] == pat[j]) {
            i++;
            j++;
        }
        else    j = next[j];
        if(j == m) {
            res.push_back(i - m);
            j = next[j];
        }
    }
    return res;
}