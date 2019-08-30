#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

#define int long long

using ii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;
using ld = long double;

#define for_(i, a, n) for(int i = a; i < n; ++i)
#define forr(i, n) for(int i = n - 1; i >= 0; ++i)
#define for0(i, n) for_(i, 0, n)
#define for1(i, n) for_(i, 1, n + 1)

#define sz(a) (int)a.size()
#define all(a) a.begin(),a.end()
#define PI acos(-1.0)
#define fs first
#define sc second
#define pb push_back
#define eb emplace_back
#define endl '\n'
#define INF INT_MAX
#define CASET int ___T; cin >> ___T; while(___T--)

namespace input {
	template<typename T> bool re(T&& t) { return (cin >> t) ? 1 : 0; }
	template<typename T1, typename T2>									// pair
	void re(pair<T1, T2> &t) { re(t.first); re(t.second); }

	template<typename T1, typename T2>									// vector
	void re_v(const T1 &n, vector<T2> &v) {
		for(int i = 0; i < n; ++i) {
			T2 in; re(in);
			v.push_back(in);
		}
	}

	template<typename T, typename... Args>
	bool re(T&& t, Args&&... args) { re(t); return re(args...); }
}

namespace output {
	template<typename T> void ou(const T& t) { cout << t; }
	template<typename T1, typename T2>									// pair
	void ou(const pair<T1, T2> &t) { ou(t.first); ou(t.second); }

	template<typename T>
	void ou_v(const vector<T> &v) {
		for(auto it = v.begin(); it != v.end(); ou(*it++))				// vector
			if(it != v.cbegin()) ou(' ');
	}

	template<typename T, typename... Args>
	void ou(const T& t, const Args&... args) { ou(t); ou(' '); ou(args...); }
}
using namespace input;
using namespace output;

namespace DEBUG {
	template<typename T> void _de(const T& t) { cerr << t; }
	template<typename T1, typename T2>									// pair
	void _de(const pair<T1, T2> &t) { cerr << '(' << t.first << ", " << t.second << ')'; }

	template<typename T>
	void pary(T t1, T t2) {
		cerr << "[";
		for(auto t = t1; t != t2; _de(*t++))
			if(t != t1) cerr << ", ";
		cerr << "]\n";
	}

	template<typename T, typename... Args>
	void _de(const T& t, const Args&... args) { cerr << t << ' '; _de(args...); }
}

#ifdef rrr
using namespace DEBUG;
#define wer(...) if(1) {																\
	cerr << __PRETTY_FUNCTION__ << " - " << __LINE__ << "(" << #__VA_ARGS__ << ") = ";	\
	_de(__VA_ARGS__, '\n');																\
}
#define werp(v) if(1) {																	\
	cerr << __PRETTY_FUNCTION__ << " - " << __LINE__ << "(" << #v << ") = ";			\
	pary(v.begin(), v.end());															\
}
#define IOS
#else
#define wer(...)
#define werp(...)
#define pary(...)
#define IOS cin.tie(NULL); ios_base::sync_with_stdio(NULL);
#endif

signed main() {
	
}
