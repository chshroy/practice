#define INF 2147483647

const int maxp = 1000005;

struct edge{ int to,rev,cap; };

struct dinic {
	
	int level[maxp],iter[maxp];
	vector<edge>G[maxp];

	void add_edge(int from, int to, int cap) {
		G[from].pb({to, (int)G[to].size(), cap});
		G[to].pb({from, (int)G[from].size()-1, cap});  //注意是無向邊，反邊的cap不為０
	}

	void bfs(int s) {
		memset(level, -1, sizeof(level));
		level[s]=0;
		queue<int>q; q.push(s);
		while(!q.empty()) {
			int v = q.front(); q.pop();
			rep0(i,(int)G[v].size()) {
				edge &e=G[v][i];
				if(e.cap>0 && level[e.to] == -1) {
					level[e.to] = level[v] + 1;
					q.push(e.to);
				}
			}
		}
		
	}

	
	int dfs(int v, int t, int f) {
		if(v==t) return f;

		for(int &i=iter[v];i<(int)G[v].size();++i) {
			edge &e = G[v][i];
			if(e.cap > 0 && level[v] < level[e.to]) {
				int d = dfs(e.to,t,min(f,e.cap));
				if(d > 0) {
					e.cap -= d;
					G[e.to][e.rev].cap += d;
					return d;
				}
			}
		}
		return 0;
	}

	int max_flow(int s, int t) {
		int flow=0;
		while(1) {
			bfs(s);
			if(level[t] == -1) return flow;
			memset(iter, 0, sizeof(iter));
			int f;
			while((f = dfs(s,t,INF))>0) flow += f;
		}
	}
} flow;
