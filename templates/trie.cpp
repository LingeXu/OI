//二进制trie
void init() {
    trie_node_cnt = 0;
    memset(trie, 0, sizeof(trie));
}

void InsertNode(int num) {
    int current = 0;
    for(int i = MAX_BITS; i >= 0;i--) {
        int bit = (num >> i) & 1;
        if(!trie[current][bit])
            trie[current][bit] = ++trie_node_cnt;
        current = trie[current][bit];
    }
}

//AC自动机
void init() {
    trie_node_cnt = 1;
    memset(trie, 0, sizeof(trie));  
    memset(end_cnt, 0, sizeof(end_cnt));
    memset(fail, 0, sizeof(fail));
    for(int i = 0; i < MAXC; i++)
        trie[0][i] = 1;
}

void Insert(const string& s) {
    int cur = 1;
    for(char c : s) {
        int idx = c - 'a';
        if(!trie[cur][idx])  
            trie[cur][idx] = ++trie_node_cnt;
        cur = trie[cur][idx];
    }
    end_cnt[cur]++;
}

void build() {
    queue<int> q;
    q.push(1);
    while(!q.empty()) {
        int x = q.front();
        q.pop();
        for(int i = 0; i < MAXC; i++) {
            if(trie[x][i]) {
                fail[trie[x][i]] = trie[fail[x]][i];
                q.push(trie[x][i]);
            }
            else trie[x][i] = trie[fail[x]][i];
        }
    }
}

int query(const string& text) {
    int cur = 1, ans = 0;
    for(char c : text) {
        int idx = c - 'a';
        cur = trie[cur][idx];
        for(int i = cur; i; i = fail[i]) 
            ans += end_cnt[i];
    }
    return ans;
}

bool contain(const string& text) {
    int cur = 1;
    for(char c : text) {
        int idx = c - 'a';
        cur = trie[cur][idx];
        for(int i = cur; i; i = fail[i]) 
            if(end_cnt[i])   
                return true;  
    }
    return false;
}