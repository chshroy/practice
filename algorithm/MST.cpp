#define pb emplace_back


#define w(i) get<0>(i)
#define from(i) get<1>(i)
#define to(i) get<2>(i)
#define used(i) get<3>(i)

const int maxn = 1e5+5;
int n,m;
vector<tuple<ll,ll,ll,bool> > g; //w,from,to

struct dsu {
	int p[maxn], rank[maxn];
	void init() {	rep0(i,n) p[i] = i, rank[i] = 1; }
	int find(int x) { return p[x] == x ? x : p[x] = find(p[x]); }
	bool u(int x, int y) {
		x = find(x), y = find(y);
		if(x == y) return false;
		if(rank[x] > rank[y]) swap(x,y);
		rank[y] += rank[x];
		p[x] = y;
		return true;
	}
};

ll MST() {
	ll sum = 0;
	int cnt = 0;
	sort(g.begin(),g.end());
	dsu d;
	d.init();
	for(auto i : g) {
		if(d.u(from(i),to(i))) {
			sum += w(i);
			used(i) = 1;
			cnt++;
		}
	}
	return cnt == n-1 ? sum : -1;
}

void init() {
	g.clear();
}

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	while(cin>>n>>m) {
		init();
		rep0(i,m) {
			int a,b,w;
			cin>>a>>b>>w;
			g.pb(w,a,b,0);
		}
		cout<<MST()<<endl;
	}
}
