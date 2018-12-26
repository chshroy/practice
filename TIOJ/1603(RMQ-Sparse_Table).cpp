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
#define p2(i) (1<<(i))
#define endl '\n'

const int maxn = 1e5+5;
unsigned int a[maxn],di[maxn][17],da[maxn][17],n,m;

void RMQ_init() {
	rep0(i,n) di[i][0] = da[i][0] = a[i];
	for(int i=1;p2(i)<=n;++i)
		for(int j=0;j<=n-p2(i);++j) {
			di[j][i] = min(di[j][i-1],di[j+p2(i-1)][i-1]);
			da[j][i] = max(da[j][i-1],da[j+p2(i-1)][i-1]);
		}
}

unsigned int RMQ(int l, int r) {
	int k = 31 - __builtin_clz(r-l+1);;
	return max(da[l][k],da[r-p2(k)+1][k])-min(di[l][k],di[r-p2(k)+1][k]);
}

int main() {
	IOS()
	cin>>n>>m;
	rep0(i,n) cin>>a[i];
	RMQ_init();
	while(m--) {
		int l, r;
		cin>>l>>r; l--, r--;
		cout<<RMQ(l,r)<<endl;
	}
}
