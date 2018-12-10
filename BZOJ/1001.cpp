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

const int maxp=1000005;

struct edge{ int to,rev,cap; };
int level[maxp],iter[maxp];
vector<edge>G[maxp];

void add_edge(int from, int to, int cap) {

	//cout<<from<<" "<<to<<" "<<cap<<endl;
	G[from].pb((edge){to,SZ(G[to]),cap});
	G[to].pb((edge){from,SZ(G[from])-1,cap});  //注意是無向邊，反邊的cap不為０
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

	for(int &i=iter[v];i<SZ(G[v]);++i) {
		edge &e=G[v][i];
		if(e.cap>0 && level[v]<level[e.to]) {
			int d = dfs(e.to,t,min(f,e.cap));
			if(d>0) {
				e.cap-=d;
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
		if(level[t]==-1) return flow;
		FILL(iter,0)
		int f;
		while((f=dfs(s,t,INF))>0) {
			flow+=f;
		}
	}
	
}

int main() {
	IOS()
	int n,m;
	cin>>n>>m;
	rep0(i,n) rep0(j,m-1) {
		int a;
		cin>>a;
		add_edge(i*m+j,i*m+1+j,a);
	}
	rep0(i,n-1) rep0(j,m) {
		int a;
		cin>>a;
		add_edge(i*m+j,(i+1)*m+j,a);
	}
	rep0(i,n-1) rep0(j,m-1) {
		int a;
		cin>>a;
		add_edge(i*m+j,(i+1)*m+1+j,a);
	}
	cout<<max_flow(0,n*m-1)<<endl;

}
