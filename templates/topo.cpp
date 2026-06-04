vector<int> graph[N];
int in_deg[N];
void topo() {
    vector<int> topo;
    memset(in_deg, 0, sizeof(in_deg)); 
    for(int i = 1; i <= n; i++) 
        for(int to : graph[i])
            in_deg[to]++;
    queue<int> q;
    for(int i = 1; i <= n; i++)
        if(in_deg[i] == 0)
            q.push(i);
    while(!q.empty()) {
        int x = q.front();
        q.pop();
        topo.push_back(x);
        for(int to : graph[x])
            if(--in_deg[to] == 0)
                q.push(to);
    }
    if(topo.size() != n)
        cout << "存在环";
}