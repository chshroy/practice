const int maxn = 2e4 + 50;
bool cut[maxn];
vector<int> G[maxn];
int depth[maxn], visit[maxn], low[maxn], cnt = 0;
void dfs(int pos, int pre, int dep) {  //dfs(1, 0, 0)
	int son = 0;
	visit[pos] = 1;
	depth[pos] = dep;
	low[pos] = dep;
	for(int u : G[pos]) if( u != pre) {
		if(visit[u]) {
			low[pos] = min(low[pos], depth[u]);
		}
		else {
			dfs(u, pos, dep+1);
			low[pos] = min(low[pos], low[u]);
			if(low[u] >= depth[pos] && depth[pos]) cut[pos] = 1;
			son++;
		}
	}
	if(dep == 0 && son > 1) cut[pos] = 1;
	if(cut[pos]) cnt++;
}
