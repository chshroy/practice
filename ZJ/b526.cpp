#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef pair<int, int> ii;
#define fs first
#define sc second
#define rep(i, a, n) for( int i = a; i < n; ++i)
#define rep0(i, n) rep(i, 0, n)
#define rep1(i, n) rep(i, 1, n+1)
#define pb push_back
#define endl '\n'


const int maxn = 4e5+50;
set<int> s;
vector<int> st;
vector<ii> v, node;
int bit[maxn] = {};

#define lowbit(i) (i&(-i))
void add(int x, int val) {
	for(int i = x; i < maxn; i += lowbit(i)) bit[i] += val;
}

int val(int x) {
	if( x == 0) return 0;
	int su = 0;
	for(int i = x; i > 0; i -= lowbit(i)) su += bit[i];
	return su % 2;
}



int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	int n, m;
	cin >> n >> m;
	rep0(i, m) {
		int r, l;
		cin >> l >> r;
		v.pb({l, r});
		s.insert(r); s.insert(r+1);
		s.insert(l); s.insert(l-1);
	}
	s.insert(-1); s.insert(1); s.insert(n); s.erase(0);
	st = vector<int> (s.begin(), s.end());
	rep0(i, m) {
		int l, r;
		l = lower_bound(st.begin(), st.end(), v[i].fs) - st.begin();
		r = lower_bound(st.begin(), st.end(), v[i].sc) - st.begin();
		add(l, 1); add(r+1, -1);
	}
	int ans = 0, stp = 0;
	for(int i = 1; i < st.size(); ++i) {
		if(val(i) == 1 && stp != 0) {
			ans += st[i-1] - stp + 1, stp = 0;
		}
		if(val(i) == 0 && stp == 0) stp = st[i];
	}
	if(stp != 0) ans += n - stp + 1;
	cout << ans << endl;
	


}
