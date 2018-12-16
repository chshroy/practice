//有多筆輸入...
#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
#define x first
#define y second
#define rep(i,a,n) for(int i=a;i<n;i++)
#define rep0(i,n) rep(i,0,n)
#define rep1(i,n) rep(i,1,n+1)
#define _ <<" "<<

int read() {
	int x=0,w=1; char c=getchar();
	while(isspace(c)) c=getchar();
	if(c=='-') w=0,c=getchar();
	while(isdigit(c)) x = (x<<3) + (x<<1) + (c^48), c=getchar();
	return w ? x : -x;
}

const int maxn = 15005, maxr = 32005;
int n;
int ans[maxn];
int bit[maxr];
ii p[maxn];

void init() {
	rep0(i,n) ans[i]=0;
	rep0(i,maxr) bit[i]=0;
}

int lowbit(int &i) { return i & -i; }

int sum(int x) {
	int su=0;
	for(int i=x;i>0;i-=lowbit(i)) su += bit[i];
	return su;
}

void add(int x, int v) {
	for(int i=x;i<=maxr;i+=lowbit(i)) bit[i] += v;
}

int main() {
	while(cin>>n) {
		init();
		rep0(i,n) p[i] = {read()+1,read()+1};
		sort(p,p+n,[](ii p1,ii p2) {
			return p1.x<p2.x || (p1.x==p2.x&&p1.y<p2.y);
		});

		rep0(i,n) {
			ans[sum(p[i].y)]++;
			add(p[i].y, 1);
		}
		rep0(i,n) cout<<ans[i]<<endl;
	}



}
