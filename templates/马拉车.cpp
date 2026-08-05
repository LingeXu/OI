string init(const string& s) {
    string res = "*";
    for(char c : s) {
        res += c;
        res += '*';
    }
    return res;
}

int manacher(const string & s) {
    int res = 0;
    string t = init(s);
    int n = t.size();
    vector<int> d(n);
    int L = -1, R = -1;
    for(int i = 0; i < n; i++) {
        int k = (i > R ? 1 : min(d[L + R - i] + 1, R - i + 1));
        while(i - k >= 0 && i + k < n && t[i - k] == t[i + k])  k++;
        d[i] = --k;
        if(i + k > R) {
            L = i - k;
            R = i + k;
        }
        res = max(res, d[i]);
    }
    return res;
}