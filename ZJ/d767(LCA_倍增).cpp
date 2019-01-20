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

const int maxn = 30005;

vector<int>G[maxn];
int n,m,q;


/////double build////
int depth[maxn], pu[maxn][20]; //parent up, max_edge above
void LCA(int pos, int pre) {
    depth[pos] = depth[pre] + 1;
    pu[pos][0] = pre;
    for(int i = 1;i<=__lg(n);++i) {
        pu[pos][i] = pu[pu[pos][i-1]][i-1];
    }
    for(auto i : G[pos]) 
        if(i!=pre) LCA(i,pos);
        
}

#define lowbit(i) ((i)&(-i))
int query(int u, int v) {
    if(depth[u]>depth[v]) swap(u,v); // v should be deeper
    int diff = depth[v] - depth[u];
    while(diff) {
        int i = __lg(lowbit(diff)); //= __builtin_ffs(diff)-1;
        v = pu[v][i];
        diff-=lowbit(diff);
    }
    for(int i=__lg(n);i>=0;--i) {
        if(pu[u][i] != pu[v][i]) {
            u = pu[u][i];
            v = pu[v][i];
        }
    }
    if(u!=v) return pu[u][0];
    return u;
}

int main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	cin>>n>>m;
	rep1(i,n) {
		int in;
		while(cin>>in && in) {
			G[i].pb(in);
			G[in].pb(i);
		}
	}
	
	LCA(1,0);

	while(m--) {
		int a, b, p;
		cin>>a>>b;
		p = query(a,b);
		cout<<p<<" "<<depth[a]+depth[b]-depth[p]*2<<endl;
	}
}
