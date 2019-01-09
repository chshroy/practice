#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,n) for(int i=a;i<n;++i)
#define rep0(i,n) rep(i,0,n)
#define rep1(i,n) rep(i,1,n+1)
#define x first
#define y second

typedef long long ll;
typedef pair<ll,ll> ii;
#define pb push_back
#define mt make_tuple
vector<ii> G[100005];

const int maxn = 1e5+5;
int n, m;

struct edge {
	int from, to, w;
	bool used;
};
vector<edge> g;

struct dsu {
	int p[maxn], rk[maxn];
	void init() { rep1(i,n) p[i] = i, rk[i] = 1; }
	int find(int i) { return i == p[i] ? i : p[i] = find(p[i]); }
	bool uni(int a, int b) {
		a = find(a), b = find(b);
		if(a == b) return false; // cannot union
		if(rk[a]>rk[b]) swap(a,b);
		p[a] = b;
		rk[b] += rk[a];
		return true;
	}
};

ll MST() {
	ll sum = 0;
	dsu d; d.init();
	sort(g.begin(),g.end(),[](edge a, edge b) { return a.w<b.w; });
	for(auto &e : g) {
		int u = e.from, v = e.to, w = e.w;
		
		if(d.uni(u, v)) {
			e.used = true;
			G[u].pb({v,w});
			G[v].pb({u,w});
			sum += w;
		}
	}
	return sum;
}

int depth[maxn], pu[maxn][20], mw[maxn][20];
void dfs(int pos, int pre, int w) {
	depth[pos] = depth[pre] + 1;
	int k = __lg(depth[pos]);
	pu[pos][0] = pre, mw[pos][0] = w;
	rep1(i,k) {
		pu[pos][i] = pu[pu[pos][i-1]][i-1];
		mw[pos][i] = max(mw[pos][i-1], mw[pu[pos][i-1]][i-1]);
	}
	for(auto e : G[pos]) if(e.x != pre) dfs(e.x, pos, e.y);
}
#define lowbit(i) (i&(-i))
int query(int u, int v) {
	int ret = 0;
	if(depth[u]>depth[v]) swap(u, v);
	int diff = depth[v] - depth[u];
	while(diff) {
		int k = __lg(lowbit(diff));
		ret = max(ret, mw[v][k]);
		v = pu[v][k];
		diff -= lowbit(diff);
	}
	for(int k = __lg(n);k>=0;k--) {
		if(pu[u][k] != pu[v][k]) {
			ret = max(ret, max(mw[u][k],mw[v][k]));
			u = pu[u][k], v = pu[v][k];
		}
	}
	if(u!=v) ret = max(ret, max(mw[u][0],mw[v][0]));
	return ret;
}

int subMST() {
	depth[1] = -1;
	dfs(1,1,0);
	int mi = 2147483647;
	for(auto e : g) if(!e.used) {
		int tmp = e.w-query(e.from, e.to);
		mi = min(mi, tmp);
	}
	return mi;
}

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	cin>>n>>m;
	rep0(i,m) {
		int a, b, w;
		cin>>a>>b>>w;
		g.pb({a,b,w,0});
	}
	ll mst = MST();
	//cout<<mst<<endl;
	ll add = subMST();
	cout<<mst<<" "<<mst+add<<endl;
	
}
