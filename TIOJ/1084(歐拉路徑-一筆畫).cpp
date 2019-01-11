#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,n) for(int i=a;i<n;i++)
#define rep0(i,n) rep(i,0,n)
#define rep1(i,n) rep(i,1,n+1)
#define pb push_back
#define endl '\n'

const int maxn = 505;
vector<int> G[maxn], ans;
int n, c[505][505], st, st2;


void add_edge(int a, int b) {
	a--, b--;
	G[a].pb(b); G[b].pb(a);
	c[a][b]++; c[b][a]++;
}

void dfs(int pos) {
	for(int i : G[pos]) {
		if(c[pos][i] == 0) continue;
		c[pos][i]--; c[i][pos]--;
		dfs(i);
	}
	ans.pb(pos);
}

void init() {
	ans.clear();
	rep0(i, 500) G[i].clear();
	memset(c, 0, sizeof(c));
	st = 2000; st2 = 2000;
}

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	while(cin>>n && n) { //n is the number of edges, not nodes xd
		init();
		rep0(i,n) {
			int a,b;
			cin>>a>>b;
			add_edge(a,b);
		}
		
		rep0(i, 500) {
			sort(G[i].begin(), G[i].end(), less<int>());
			if(G[i].size()%2 == 1) st2 = min(st2, i); //odd point
			else if(G[i].size()) st = min(st, i); //start from any points which exist
		} 
		if(st2 != 2000) st = st2;
		
		dfs(st);
		
		for(int i=ans.size()-1;i>=0;--i) 
			cout<<ans[i]+1<<endl;
	
		cout<<endl;
	}
}
