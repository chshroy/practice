namespace DSU {
	int p[maxn], sz[maxn] {};
	void init() {
		for(int i = 0; i < maxn; i++) p[i] = i;
	}

	int find(int x) {
		return x == p[x] ? x : p[x] = find(p[x]);
	}

	void uni(int a, int b) {
		if(sz[a] < sz[b]) swap(a, b);
		a = find(a), b = find(b);
		sz[b] += sz[a];
		p[a] = b;
	}
};
using namespace DSU;
