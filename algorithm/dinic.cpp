const int maxn = 1e6;

struct edge {
	int to, rev, cap;
};

struct DINIC {
	int s, t;
	vector<edge> G[maxn];
	void add_edge(int u, int v, int w) {
		G[u].pb({v, G[v].size(), w});
		G[v].pb({u, G[u].size() - 1, w}); // 無向邊 
	}
	int iter[maxn], depth[maxn]; // d -> depth
	bool bfs() {
		//cout << "bfs\n";
		memset(depth, -1, sizeof(depth));
		queue<int> q; q.push(s);
		depth[s] = 0;
		while(!q.empty()) {
			int u = q.front(); q.pop();
			for(edge e : G[u]) {
				int v = e.to;
				if(depth[v] != -1 || e.cap == 0) continue;
				depth[v] = depth[u] + 1;
				q.push(v);
			}
		}
		return depth[t] != -1;
	}
	
	int dfs(int pos, int f) {
		//cout << "dfs\n";
		if(pos == t) return f;
		for(int &i = iter[pos]; i < G[pos].size(); ++i) {
			edge &e = G[pos][i];
			if(e.cap == 0 || depth[e.to] <= depth[pos]) continue;
			int d = dfs(e.to, min(f, e.cap));
			if(d) {
				e.cap -= d;
				G[e.to][e.rev].cap += d;
				return d;
			}
		}
		return 0;
	}
	
	int max_flow() {
		int flow = 0;
		while(bfs()) {
			memset(iter, 0, sizeof(iter));
			int f = 0;
			while(f = dfs(s, INT_MAX)) {
				flow += f;
			}
		}
		return flow;
	}
} dinic;
