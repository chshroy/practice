#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
#define rep(i,a,n) for(int i=a;i<n;++i)
#define rep0(i,n) rep(i,0,n)
#define rep1(i,n) rep(i,1,n+1)
#define pb push_back
#define x first
#define	y second 
#define p2(i) (1<<(i))
#define wer(x) cout<<(#x)<<" "<<x<<endl;

const int maxn = 40005;
vector<ii>G[maxn];
int io[maxn*4];
int pin[maxn],tot,d[maxn],rm[maxn*4][14];

void dfs(int pos, int pre, int dis) {
	d[pos] = dis;
	io[tot] = pos;
	pin[pos]=tot++;
	
	for(auto i:G[pos]) if(i.x!=pre)	
		dfs(i.x, pos, dis+i.y),io[tot++] = pos;;
	
	io[tot++] = pos;
}

void build_RMQ() {
	//build RMQ from io
	rep0(i,tot) rm[i][0] = io[i];
	rep1(k,__lg(tot))
		for(int i=0;i<=tot-p2(k);i++) 
			rm[i][k] = min(rm[i][k-1],rm[i+p2(k-1)][k-1]);
}

int query(int l, int r) {
	int k = __lg(r-l+1);
	return min(rm[l][k], rm[r-p2(k)+1][k]);
}

int main() {
	int t,n,q,a,b,w,lca,pa,pb;
	cin>>t;
	while(t--) {
		tot=0;
		cin>>n>>q;
		rep0(i,n-1) {
			cin>>a>>b>>w;
			G[a].pb({b,w}); G[b].pb({a,w});
		}
		dfs(1,0,0);
		build_RMQ();
		/*
		rep0(i,tot) cout<<io[i]<<" "; cout<<endl;
		rep1(i,n) cout<<pin[i]<<" "; cout<<endl;
		rep1(i,n) cout<<d[i]<<" "; cout<<endl;
		*/
		rep0(i,q) {
			cin>>a>>b;
			pa = pin[a], pb = pin[b];
			lca = query(min(pa,pb), max(pa,pb));
			cout<<d[a]+d[b]-d[lca]*2<<endl;
		}
	}
	
}
