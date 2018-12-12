#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,n) for(int i=a;i<n;++i)
#define rep0(i,n) rep(i,0,n)
#define rep1(i,n) rep(i,1,n+1)
#define x first
#define y second
#define pb push_back
#define FILL(i,n) memset(i,n,sizeof i);
#define SZ(i) (int)i.size()
#define INF 0x3f3f3f
#define IOS() cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

struct edge{ int to,rev,cap; }; 

const int maxp=45,maxn=125000;
int point[maxp][maxp][maxp],level[maxn],iter[maxn];
vector<edge>G[maxn];


void add_edge(int from, int to, int cap) {
	G[from].pb({to,SZ(G[to]),cap});
	G[to].pb({from,SZ(G[from])-1,0});
}

void bfs(int s) {
	FILL(level,-1) 
	level[s]=0;
	queue<int>q; q.push(s);
	while(!q.empty()) {
		int v=q.front(); q.pop();
		rep0(i,SZ(G[v])) {
			edge &e=G[v][i];
			if(e.cap>0 && level[e.to]==-1) {
				level[e.to] = level[v]+1;
				q.push(e.to);
			}
		}
	}
}

int dfs(int v, int t, int f) {
	if(v==t) return f;
	for(int &i=iter[v];i<SZ(G[v]);i++) {
		edge &e=G[v][i];
		if(e.cap>0 && level[e.to]>level[v]) {
			int d=dfs(e.to,t,min(f,e.cap));
			if(d>0) {
				e.cap-=d;
				G[e.to][e.rev].cap+=d;
				return d;
			}
		}
	}
	return 0;
}

int max_flow(int s, int t) {
	int flow=0,f;
	while(1) {
		bfs(s);
		if(level[t]==-1) return flow;
		FILL(iter,0)
		while((f=dfs(s,t,INF))>0) flow+=f;
	}
}



int main() {
	int p,q,r,d;
	cin>>p>>q>>r>>d;
	int tot=0,source,sink;
	source=0;
	rep0(i,p) rep0(j,q) rep0(k,r) point[i][j][k]=++tot;
	sink=++tot;
	rep0(i,p) rep0(j,q) add_edge(source,point[i][j][0],INF);
	rep0(i,r-1) rep0(j,p) rep0(k,q) {
		int in; cin>>in;
		add_edge(point[j][k][i],point[j][k][i+1],in);
	}
	rep0(i,p)rep0(j,q) {
		int in; cin>>in;
		add_edge(point[i][j][r-1],sink,in);
	}
	int dx[4]={0,0,1,-1},dy[4]={-1,1,0,0};
	rep0(i,p) rep0(j,q) rep(k,d,r) {
		rep0(l,4) {
			int cx=i+dx[l],cy=j+dy[l];
			if(cx>=0 && cy>=0)
				add_edge(point[i][j][k],point[cx][cy][k-d],INF);
		}
	}
	cout<<max_flow(source,sink)<<endl;
}
