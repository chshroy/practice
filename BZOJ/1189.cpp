//#define bug
   
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double lf;
typedef pair<ll,ll> ii;
typedef pair<ii,int> pii;
#define rep(i,a,n) for(ll i=a;i<n;i++)
#define rep0(i,n) for(ll i=0;i<n;i++)
#define rep1(i,n) for(ll i=1;i<=n;i++)
#define FILL(i,n) memset(i,n,sizeof i)
#define x first
#define y second
#define _ <<" "<<
#define SZ(_a) (int)_a.size()
#define ALL(_a) _a.begin(),_a.end()
#define pb push_back
#define IOS() ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define INF 0x3f3f3f3f
   
#ifdef bug
#define wer(x) cout<<(#x)<<" "<<(x)<<endl;
#define we(x) cout<<(#x)<<" "<<(x)<<" ";
#else
#define wer(x)
#define we(x)
#endif

struct edge { int to,cap,rev; };
const int MAXN = 25;
const int MAXM = 405;
const int MAXP = 160005;
vector<edge> G[MAXP];
int level[MAXP];
int iter[MAXP];
   
int n,m,source,sink,goal;
char mp[MAXN][MAXN];
int point[MAXM][MAXN][MAXN];
   
void add_edge(int from, int to, int cap) {
    G[from].pb((edge){to,cap,SZ(G[to])});
    G[to].pb((edge){from,0,SZ(G[from])-1});
}
   
void bfs(int s) {
    memset(level,-1,sizeof(level));
    queue<int>q;
    level[s] = 0;
    q.push(s);
    while(!q.empty()) {
        int v=q.front(); q.pop();
        rep0(i,SZ(G[v])) {
            edge &e = G[v][i];
            if(e.cap>0 && level[e.to] < 0) {
                level[e.to] = level[v] + 1;
                q.push(e.to);
            }
        }
    }
}
   
int dfs(int v, int t, int f) {
    if(v == t) return f;
    for(int &i=iter[v];i<SZ(G[v]);++i) {
        edge &e = G[v][i];
        if(e.cap > 0 && level[v]<level[e.to]) {
            int d = dfs(e.to, t, min(f,e.cap));
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
    int flow = 0;
    while(1) {
        bfs(s);
        if(level[t]<0) return flow;
        memset(iter,0,sizeof(iter));
        int f;
        while((f=dfs(s,t,INF))>0) flow+=f;
    }
}
   
int main() {
		IOS()
    memset(mp,0,sizeof(mp));
    //input
    cin>>n>>m;
    rep1(i,n) rep1(j,m) 
			cin>>mp[i][j];
   
    //init
    int tot=0;
    source=goal=0;
    rep0(ans,n*m+1) rep1(i,n) rep1(j,m)
        if(mp[i][j]=='.') point[ans][i][j]=++tot;
       
    sink = ++tot;
    rep1(i,n)rep1(j,m) 
        if(mp[i][j]=='.') add_edge(source,point[0][i][j],1), goal++;
   
    int dx[5]={0,0,1,0,-1},dy[5]={0,1,0,-1,0},mf=0;
    rep1(ans,n*m) {
        int tmp=ans-1;
        rep1(i,n) rep1(j,m) {
            if(mp[i][j]!='.') continue; 
            rep0(k,5) {
                int i2=i+dx[k],j2=j+dy[k];
                //四周有'.'，表示上一秒有路可以走過來  ***注意可以有很多個人同時走過來!!! 
                if(mp[i2][j2]=='.') add_edge(point[tmp][i][j],point[ans][i2][j2],INF);
                else if(mp[i2][j2]=='D') add_edge(point[tmp][i][j],sink,1);
            }
        }
        mf+=max_flow(source,sink);  //每一秒逃出來的人數加起來 
        we(ans)we(mf)wer(goal)
           
        if(mf==goal) {
            cout<<ans<<endl;
            return 0;
        }
    }
    cout<<"impossible\n";
    return 0;
}
