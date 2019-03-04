//https://toj.tfcis.org/oj/pro/207/
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> ii;

#define rep(i, a, n) for(int i = a; i < n; ++i)
#define rep0(i, n) rep(i, 0, n)
#define rep1(i, n) rep(i, 1, n+1)
#define fs first
#define sc second
#define pb push_back
#define eb emplace_back
#define IOS cin.tie(0); ios_base::sync_with_stdio(0);

const int maxn = 20005;
int n;

struct DSU {
    int p[maxn], sz[maxn];
    
    void init() {
        rep0(i, n) p[i] = i, sz[i] = 1;
    }    
    
    int find(int x) {
        return x == p[x] ? x : p[x] = find(p[x]);
    }
    
    void uni(int x, int y) {
        // x, y must be parent
        if(sz[x] < sz[y]) swap(x, y);
        p[y] = x;
        sz[y] += x;
    }
} dsu;

struct edge{
    int u, v, w;
    bool used;
    bool operator < ( const edge e) const {
        return w < e.w;
    }
};

vector<ii> G[maxn];

struct MST {
    vector<edge> E;
    
    void init() {
        E.clear();
    }
    
    void add_edge(int u, int v, int w) {
        E.pb({u, v, w, 0});
    }
    
    int build() {
        int rt = 0;
        sort(E.begin(), E.end());
        for(auto &e : E) {
            int u = e.u, v = e.v, w = e.w;
            u = dsu.find(u); v = dsu.find(v);
            //cout << u << " " << v <<endl;
            if(u == v) continue;
            e.used = 1;
            dsu.uni(u, v);
            rt += w;
            G[u].eb(v, w); G[v].eb(u, w);
            
        }
        return rt;
    }
} mst;

struct LCA {
    int p[maxn][50] = {}, ma[maxn][50] = {}, depth[maxn] = {};
    
    void init() {
        memset(p, 0, sizeof(p));
        memset(ma, 0, sizeof(ma));
        memset(depth, 0, sizeof(depth));
    }
    
    void dfs(int pos, int pre) {
        depth[pos] = depth[pre] + 1;
        rep1(i, __lg(depth[pos])) {
            ma[pos][i] = max(ma[pos][i-1], ma[p[pos][i-1]][i-1]);
            p[pos][i] = p[p[pos][i-1]][i-1];
        }
        for(auto e : G[pos]) if(e.fs != pre) {
            p[e.fs][0] = pos;
            ma[e.fs][0] = e.sc;
            dfs(e.fs, pos);
        }
    }
    
    void build() {
        dfs(0, 0);
    }
    
    int query(int x, int y) {
        if(depth[x] > depth[y]) swap(x, y);
        //y jump
        #define lowbit(i) (i&(-i))
        int diff = depth[y] - depth[x], rt = 0;
        while(diff) {
            int lb = lowbit(diff); //lb = 2 ^ ?
            int jp = __lg(lb);
            rt = max(rt, ma[y][jp]);
            y = p[y][jp];
            diff -= lb;
        }
        
        for(int i = __lg(n); i >= 0; i--) {
            if(p[x][i] != p[y][i]) {
                rt = max(rt, max(ma[x][i], ma[y][i]));
                x = p[x][i]; y = p[y][i];
            }
        }
        
        if(x != y) rt = max(rt, max(ma[x][0], ma[y][0]));
        return rt;
    }
} lca;

void init() {
    rep0(i, n) G[i].clear();
    dsu.init();
    lca.init();
    mst.init();
}

signed main() {
    //freopen("in.txt", "r", stdin);
    int t, m;
    cin >> t;
    while(t--) {
        cin >> n >> m;
        init();
        rep0(i, m) {
            int a, b, w;
            cin >> a >> b >> w;
            mst.add_edge(a, b, w);
        }
        //int mst_val = mst.build();
        //cout << mst_val << endl;
        //LCA lca;
        mst.build();
        lca.build();
        int ans = INT_MAX;
        for(auto e : mst.E) if(e.used == 0){
            int q = e.w - lca.query(e.u, e.v);
            if(q) ans = min(ans, q);
        }
        cout << ans << endl;
    }
}
