// len(u, v)
// lca(u, v)

const int maxn = 1e5 + 50;
int up[maxn][50]{}, depth[maxn]{};
vector<int> edge[maxn];
 
void init(int root) {
    function<void (int, int)> dfs = [&](int u, int pre) {
        depth[u] = depth[pre] + 1;
        for(int i = 0, v = pre; i < 31; i++) {
            up[u][i] = v;
            v = up[v][i];
        }
        for(auto v : edge[u]) if(v != pre) {
            dfs(v, u);
        }
    };
    dfs(root, root);
}
 
int lca(int u, int v) {
    if(depth[u] < depth[v]) swap(u, v);
    int diff = depth[u] - depth[v];
    while(diff) {
        int jump = diff & (-diff);
        u = up[u][__lg(jump)];
        diff -= jump;
    }
    for(int i = 31; i >= 0; i--) if(up[u][i] != up[v][i]) {
        u = up[u][i];
        v = up[v][i];
    }
    return (u == v ? u : up[u][0]);
}
 
int len(int u, int v) {
    return depth[u] + depth[v] - 2 * depth[lca(u, v)];
}
