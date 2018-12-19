#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> ii;
#define x first
#define y second
#define rep(i,a,n) for(int i=a;i<n;i++)
#define rep0(i,n) rep(i,0,n)
#define rep1(i,n) rep(i,1,n+1)
#define pb push_back
#define SZ(x) (int)x.size()
#define INF 2147483647
#define wer(x) cout<<(#x)<<"->"<<x<<endl;

int read() {
	int x=0,w=1; char c=getchar();
	while(isspace(c)) c = getchar();
	if(c == '-') w=0, c = getchar();
	while(isdigit(c)) x = (x<<3) + (x<<1) + (c^48), c = getchar();
	return w ? x : -x;
}

ii a[3005];
int dp[3005][3005];
int n, k, X, D;

void add(deque<ii>&d, int idx, int val) {
	while(!d.empty() && d.front().x<=idx-D) d.pop_front();
	while(!d.empty() && d.back().y<val) d.pop_back();
	d.push_back(ii(idx, val));
}

int main() {
	n = read(), k = read()+1, X = read(), D = read();
	rep0(i,n) a[i].x = read(), a[i].y = read();
	a[n] = {X,0};
	sort(a,a+n);
	deque<ii>d;
	add(d, 0, 0);
	rep1(j,k) {
		rep0(i,n+1) {
			if(d.empty()) {
				dp[j][i] = -INF;
			}
			else {
				dp[j][i] = d.front().y + a[i].y;
			}
			add(d, a[i].x, dp[j-1][i]);
		}
		d.clear();
	}
	cout<<dp[k][n]<<endl;

}
