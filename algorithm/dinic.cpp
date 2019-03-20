// DINIC dinie(s, t)
// dinic.add_edge()
// dinic.max_flow
const int maxn = 10005;
struct edge {
    int to, rev, w;
};
struct DINIC {
#define INF INT_MAX
    int s, t;
    vector<edge> G[maxn];
    int lev[maxn], iter[maxn];
    DINIC(const int &s, const int &t) : s(s), t(t) {}
    void add_edge(int u, int v, int w) {
        G[u].pb({v, (int)G[v].size(), w});
        G[v].pb({u, (int)G[u].size() - 1, 0});
    }

    bool bfs() {
        memset(lev, -1, sizeof(lev));
        lev[s] = 0;
        queue<int> q; q.push(s);
        while(!q.empty()) {
            int u = q.front(); q.pop();
            for(auto e : G[u]) if(e.w && lev[e.to] == -1) {
                lev[e.to] = lev[u] + 1;
                q.push(e.to);
            }
        }
        return lev[t] != -1;
    }

    int dfs(int u, int f) {
        if(u == t) return f;
        for(int &i = iter[u]; i < G[u].size(); ++i) {
            auto &e = G[u][i];
            if(e.w && lev[e.to] > lev[u]) {
                int d = dfs(e.to, min(f, e.w));
                if(d) {
                    e.w -= d;
                    G[e.to][e.rev].w += d;
                    return d;
                }
            }
        }
        return 0;
    }

    int max_flow() {
        int flow = 0;
        while(bfs()) {
            memset(iter, 0, sizeof(iter));
            int f;
            while((f = dfs(s, INF))) flow += f;
        }
        return flow;
    }
    
};
