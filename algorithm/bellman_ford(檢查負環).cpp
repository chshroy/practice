const int maxn = 1e6;
struct edge {
	int from, to, w;
};
vector<edge> E;
int d[maxn];
bool bellman(int n) {
	rep0(i, maxn) d[maxn] = INT_MAX;
	d[1] = 0;
	rep0(i, n) {
		for(edge e : E) {
			edge e = E[j];
			if(d[e.from] != INT_MAX && d[e.from] + e.w < d[e.to]) {
				d[e.to] = d[e.from] + e.w;
				if(i == n - 1) {
					return true;
				}
			}
		}
	}
	return false;
}
