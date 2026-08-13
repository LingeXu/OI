s.substr(pos, len);             //不改变s, 返回截取的子串
s.insert(pos, t);           
s.erase(pos, len);              //改变s
s.find(t, pos);                 //找不到时返回string::npos
s.replace(pos, len, t);
s.push_back(c);
s.pop_back();
reverse(s.begin(), s.end());
stoi(s);                        //字符串转int
to_string(n);                   //数字转字符串

//字符串分割

//法一
string s = "hello world csp";
stringstream ss(s);
string t;
while(ss >> t) {
    cout << t << endl;  // 依次输出: hello / world / csp
}

//法二
int pos = 0;
while(pos < (int)s.size()) {
    if(s.find(' ', pos) == string::npos) {
        string word = s.substr(pos);
        break;
    }
    string word = s.substr(pos, space - pos);
    pos = space + 1;
}

//字符操作             
isdigit(c);   // 数字
isalpha(c);   // 字母
islower(c);   // 小写
isupper(c);   // 大写
toupper(c);   // 转大写
tolower(c);   // 转小写