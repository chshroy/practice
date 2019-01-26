struct dsu {
	int n;
	int p[10005], sz[10005];

	void init() {
		rep1(i,n) p[i] = i, sz[i] = 1;
	}

	int find(int x) {
		return x == p[x] ? x : p[x] = find(p[x]);
	}

	void uni(int x, int y) {
		x = find(x), y = find(y);
		if(sz[x] > sz[y]) swap(x, y);
		p[x] = y;
	}

	bool query(int x, int y) {
		return find(x) == find(y);
	}
};
