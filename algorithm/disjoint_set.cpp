struct DSU {
    int p[maxn], sz[maxn];
    
    void init() {
        for(int i = 0; i < maxn; ++i) p[i] = i, sz[i] = 1;
    }    
    
    int find(int x) {
        return x == p[x] ? x : p[x] = find(p[x]);
    }
    
    void uni(int x, int y) {
        // x, y must be parent
        if(sz[x] < sz[y]) swap(x, y);
        p[y] = x;
        sz[x] += sz[y];
    }
} dsu;
