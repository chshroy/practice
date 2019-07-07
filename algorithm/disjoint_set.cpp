struct DSU {
    int p[maxn], sz[maxn];

    DSU() {
        for(int i = 0; i < maxn; ++i) p[i] = i, sz[i] = 1;
    }

    int find(const int &x) {
        return x == p[x] ? x : p[x] = find(p[x]);
    }

    bool uni(int x, int y) {
        // x, y must be parent
		x = find(x), y = find(y);
		if(x == y) return false;
        if(sz[x] < sz[y]) swap(x, y);
        p[y] = x;
        sz[x] += sz[y];
		return true;
    }
} dsu;
