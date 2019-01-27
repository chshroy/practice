// https://codeforces.com/problemset/problem/770/C
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> ii;
#define rep(i,a,n) for(int i=a;i<n;++i)
#define rep0(i,n) rep(i,0,n)
#define rep1(i,n) rep(i,1,n+1)
#define fs first
#define sc second
#define pb push_back

const int maxn = 1e5+5;
vector<int> to, G[maxn], v;
int visit[maxn] = {0};
int n, k, in;

void dfs(int pos) {
	if(visit[pos] == 2) return;
	visit[pos] = 1; //正在走的路上 
	for(int i : G[pos]) {
		if(visit[i] == 1) { //有環
			cout<<"-1\n";
			exit(0);
		}
		dfs(i);
	}
	v.pb(pos);
	visit[pos] = 2; //走完了，紀錄已走過
}

int main() {
	cin>>n>>k;
	rep0(i,k) cin>>in, to.pb(in);
	rep1(i,n) {
		cin>>k;
		while(k--) cin>>in, G[i].pb(in);
	}

	for(int i : to) {
		dfs(i);
	}
	cout<<v.size()<<endl;
	for(int i : v) cout<<i<<" "; cout<<endl;
}
