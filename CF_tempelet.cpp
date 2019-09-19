/*
int n;
vec v;
rvec(n, v);
ou(v);
*/
#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

using ii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using vec = vector<int>;

#define for0(i, n) for(int i = 0; i < n; ++i)
#define for1(i, n) for(int i = 1; i <= n; ++i)
#define fs first
#define sc second
#define sz(a) (int)a.size()
#define all(a) a.begin(), a.end()
#define pb push_back
#define CASE int _T; cin >> _T; for1(tt, _T)

namespace royyaha {
	// input
	template<typename T> bool re(T& x) { return (cin >> x) ? 1 : 0; }
	bool re(double& x) { return (cin >> x) ? 1 : 0; }
	bool re(long double& x) { return (cin >> x) ? 1 : 0; }
	template<typename T1, typename T2> 
	void re(pair<T1, T2> &x) { re(x.first); re(x.second); }
	template<typename T1, typename T2>													// vector
	void rvec(const T1 &n, vector<T2> &v) {
		v.resize(n); for0(i, n) re(v[i]);
	}
	template<typename T, typename... Args>
	void re(T& x, Args&... rest) { re(x); re(rest...); }

	//output
	template<typename T> void pr(const T& x) { cout << x; }
	template<typename T1, typename T2> 
	void pr(const pair<T1, T2>& x) { 
		cout << x.first << " " << x.second;
    }
    template<typename T, typename... Args> 
	void pr(const T& x, const Args&... rest) {
        pr(x); pr(rest...);
    }

	template<typename T> void ou(const T& x) { pr(x); cout << endl; }
	template<typename T, typename... Args>
	void ou(const T& x, const Args&... rest) { pr(x, ' '); ou(rest...); }
	template<typename T>
	void ou(const vector<T> &v) {
		for(auto it = v.begin(); it != v.end(); ++it) {									// vector
			if(it + 1 == v.end()) ou(*it);
			else pr(*it, ' ');
		}
	}

}
using namespace royyaha;

#ifdef rrr
#define wer(...) if(1) {																\
	cerr << __PRETTY_FUNCTION__ << " - " << __LINE__ << "(" << #__VA_ARGS__ << ") = ";	\
	ou(__VA_ARGS__);																	\
}
#define IOS
#else
#define wer(...)
#define IOS cin.tie(NULL); ios_base::sync_with_stdio(NULL);
#endif

signed main() { IOS
}
