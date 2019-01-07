#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,n) for(int i=a;i<n;++i)
#define rep0(i,n) rep(i,0,n)
#define rep1(i,n) rep(i,1,n+1)
#define pb push_back
#define endl '\n'

const int maxn = 1e5+5;
struct edge { 
	int from, to, w; 
	bool operator < (const edge &e) const {
		return w<e.w;
	}
};
vector<edge>g;
int n,m,p[maxn],rk[maxn];

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

int build() {
	int sum = 0, cnt = 0;
	sort(g.begin(), g.end());
	for(auto e : g) {
		if(djs(e.from, e.to)) sum+=e.w, cnt++;
	}
	return cnt==n-1?sum:-1;
}

void init() {
	memset(rk, 0, sizeof(rk));
	rep1(i,n) p[i] = i, rk[i] = 1;
	g.clear();
}

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	while(cin>>n>>m && (n|m) ) {
		init();
		rep0(i,m) {
			int a,b,w;
			cin>>a>>b>>w;
			g.pb({a,b,w});
		}
		cout<<build()<<endl;
	}
	
}
