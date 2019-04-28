struct DSU {
    int p[maxn], sz[maxn];
    
    DSU() {
        for(int i = 0; i < maxn; ++i) p[i] = i, sz[i] = 1;
    }    
    
    int find(int x) {
        return x == p[x] ? x : p[x] = find(p[x]);
    }
    
    bool same(int &x, int &y) {
        x = find(x), y = find(y);
        return x == y;
    }
    void uni(int x, int y) {
        // x, y must be parent
        if(sz[x] < sz[y]) swap(x, y);
        p[y] = x;
        sz[x] += sz[y];
    }
};
