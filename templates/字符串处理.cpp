string s, t;
s.substr(pos, len);         //不改变s, 返回截取的子串
s.insert(pos, t);           //改变s
s.erase(pos, len);          //改变s
s.find(t, pos);             //找不到时返回string::npos
s.replace(pos, len, t);
s.push_back(c);
s.pop_back();
reverse(s.begin(), s.end());//reverse 是 STL 算法，不是 string 的成员函数 (反向迭代器r, 例: rbegin,rend)
stoi(s);                    //字符串转int
to_string(n);               //数字转字符串

//字符串分割
string s = "hello world csp";
stringstream ss(s);
string t;
while(ss >> t) {
    cout << t << endl;  // 依次输出: hello / world / csp
}

char c;              
isdigit(c);   // 数字
isalpha(c);   // 字母
islower(c);   // 小写
isupper(c);   // 大写
toupper(c);   // 转大写
tolower(c);   // 转小写