#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,n) for(int i=a;i<n;++i)
#define rep0(i,n) rep(i,0,n)
#define rep1(i,n) rep(i,1,n+1)
#define endl '\n'
#define pb push_back

vector<int> G[2005][2]; //G[i][0] = 0
int m, n, k, l;
bool b[2005]={0}; //can be start or end
bool visit[2005];
int ans = 0;

void dfs(int pos, int depth, int kind) {
	if(visit[pos]) return;
	visit[pos] = 1;

	if(b[pos]) ans = max(ans, depth);
	
	for(int i : G[pos][!kind]) 
		dfs(i, depth+1, !kind);

	visit[pos] = 0;
}

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

	while(cin>>m>>n>>k>>l) {
		memset(b,0,sizeof(b));
		rep1(i,n+m) rep0(j,2) G[i][j].clear();
		ans = 0;
		rep0(i,k) {
			int a, b, in;
			cin>>a>>b>>in;
			b += m;
			G[a][in].pb(b);
			G[b][in].pb(a);
		}
		
		rep1(i,m+n) if(G[i][1].empty()) b[i] = 1;
		rep1(i,m+n) if(b[i]) {
			dfs(i,0,1);
		}
		cout<<(ans==0?-1:ans)<<endl;
	}
}
