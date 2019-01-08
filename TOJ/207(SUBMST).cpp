//https://toj.tfcis.org/oj/pro/207/
#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
#define x first
#define y second
#define rep(i,a,n) for(int i=a;i<n;++i)
#define rep0(i,n) rep(i,0,n)
#define rep1(i,n) rep(i,1,n+1)
#define pb push_back
#define endl '\n'
#define wer(x) cerr<<(#x)<<"->"<<x<<endl;

const int maxn = 20005;
struct edge { 
    int from, to, w;
    bool used; 
    bool operator < (const edge &e) const {
        return w<e.w;
    }
};
vector<edge>g;
vector<ii>G[maxn];
int n,m,p[maxn],rk[maxn],q;

int getp(int u) {
    return p[u] == u ? u : p[u] = getp(p[u]);
}

bool djs(int u, int v) {
    u = getp(u), v = getp(v);
    if(u == v) return 0;
    if(rk[u] > rk[v]) {
        rk[v] += rk[u];
        p[u] = v;
    }
    else {
        rk[u] += rk[v];
        p[v] = u;
    }
    return 1;
}

void build() {
    sort(g.begin(), g.end());
    for(auto &e : g) {
        if(djs(e.from, e.to)) {
            e.used = 1;
            G[e.from].pb({e.to,e.w});
            G[e.to].pb({e.from,e.w});
        }
    }
}

/////double build////
int depth[maxn], pu[maxn][20], me[maxn][20]; //parent up, max_edge above
void LCA(int pos, int pre, int w) {
    depth[pos] = depth[pre] + 1;
    pu[pos][0] = pre;
    me[pos][0] = w;
    for(int i = 1;i<=__lg(n);++i) {
        pu[pos][i] = pu[pu[pos][i-1]][i-1];
        me[pos][i] = max(me[pos][i-1], me[pu[pos][i-1]][i-1]);
    }
    for(auto e:G[pos]) 
        if(e.x!=pre) LCA(e.x,pos,e.y);
        
}

#define lowbit(i) ((i)&(-i))
int query(int u, int v) {
    int ret = 0;
    if(depth[u]>depth[v]) swap(u,v); // v should be deeper
    int diff = depth[v] - depth[u];
    while(diff) {
        int i = __lg(lowbit(diff)); //= __builtin_ffs(diff)-1;
        ret = max(ret, me[v][i]);
        v = pu[v][i];
        diff-=lowbit(diff);
    }
    for(int i=__lg(n);i>=0;--i) {
        if(pu[u][i] != pu[v][i]) {
            ret = max(ret, max(me[u][i],me[v][i]));
            u = pu[u][i];
            v = pu[v][i];
        }
    }
    if(u!=v) ret = max(ret, max(me[u][0],me[v][0]));
    return ret;
}

void init() {
    rep0(i,n) p[i] = i, rk[i] = 1, depth[i] = 0, G[i].clear();
    g.clear();
}
int main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int t;
    cin>>t;
    while(t--) {
        cin>>n>>m;
        init();
        rep0(i,m) {
            int a,b,w;
            cin>>a>>b>>w;
            g.pb({a,b,w,0});
        }
        build();
        LCA(0,0,0);
        int ans = 2147483647;
        for(auto e : g) {
            if(e.used==false) {
                int tmp = e.w-query(e.from, e.to);
                if(tmp!=0) ans = min(ans, tmp); 
            }
        }
        cout<<ans<<endl;
    }
    
}
