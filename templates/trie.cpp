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

//字典树
void init() {
    trie_node_cnt = 0;
    memset(trie, 0, sizeof(trie));
    memset(pass_cnt, 0, sizeof(pass_cnt));
    memset(end_cnt, 0, sizeof(end_cnt));
    memset(sum_cnt, 0, sizeof(sum_cnt));
}

void AddWord(const string& word) {
    int current = 0;
    for(char c : word) {
        int idx = c - 'a';
        if(!trie[current][idx])
            trie[current][idx] = ++trie_node_cnt;
        current = trie[current][idx];
        pass_cnt[current]++;
    }
    end_cnt[current]++;
}

void build() {
    queue<int> q;
    for(int i = 0; i < MAXC; i++) {
        if(trie[0][i]) {
            fail[trie[0][i]] = 0;
            q.push(trie[0][i]);
        }
    }
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(int i = 0; i < MAXC; i++) {
            if(trie[u][i]) {
                fail[trie[u][i]] = trie[fail[u]][i];
                sum_cnt[trie[u][i]] = end_cnt[trie[u][i]] + sum_cnt[fail[trie[u][i]]];
                q.push(trie[u][i]);
            }
            else    trie[u][i] = trie[fail[u]][i];
        }
    }
}

int query(const string& word) {
    int current = 0, res = 0;
    for(char c : word) {
        int idx = c - 'a';
        current = trie[current][idx];
        res += sum_cnt[current];
    }
    return res;
}