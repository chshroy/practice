
#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

#define int long long
using ii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;

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
#define CASET int ___T; cin >> ___T; for_1(cs, ___T)

namespace input {
	template<typename T> void re(T&& t) { cin >> t; }
	template<typename T1, typename T2>									// pair
	void re(pair<T1, T2> &&t) { re(t.first); re(t.second); }

	template<typename T>
	void re(int &&n, vector<T> &&v) {									// vector
		re(n); v.reserve(n); for(int i = 0; i < n; re(v[i++]));
	}

	template<typename T, typename... Args> 
	void re(T&& t, Args&&... args) { re(t); re(args...); }
}

namespace output {
	template<typename T> void ou(T&& t) { cout << t; }
	template<typename T1, typename T2>									// pair
	void ou(pair<T1, T2> &&t) { ou(t.first); ou(t.second); }

	template<typename T>
	void ou(vector<T> &v) {												// vector
		for(int i = 0; i < (int)v.size(); ou(v[i++])) if(i) ou(' ');
	}

	template<typename T, typename... Args> 
	void ou(T&& t, Args&&... args) { ou(t, ' '); ou(args...); }
};
using namespace input;
using namespace output;
/*
input(a, b, c);
input(n, v); // v is vector
output(a, b, c);
output(v);
*/

#ifdef rrr
#define wer(...) if(1) {                                                                \
    fprintf(stderr, "%s - %d (%s) = ", __PRETTY_FUNCTION__, __LINE__, #__VA_ARGS__);    \
    _do(__VA_ARGS__);                                                                   \
}
template<typename T>void _do(T &&_x){ cerr << _x << endl; }
template<typename T, typename ...S> void _do(T &&_x, S &&..._t){ cerr << _x << " ," ; _do(_t...); }
template<typename _a,typename _b> ostream& operator << (ostream &_s, const pair<_a, _b> &_p) {
    return _s<<"("<<_p.X<<","<<_p.Y<<")";
}
template<typename It> ostream& _OUTC(ostream &_s, It _ita, It _itb)
{
    _s << '{';
    for(It _it = _ita; _it != _itb ;_it++)
    {
        _s << (_it == _ita ? "" : ",") << *_it;
    }
    _s << '}';
    return _s;
}
template<typename _a> ostream &operator << (ostream &_s, vector<_a> &_c){ return _OUTC(_s, ALL(_c)); }
template<typename _a> ostream &operator << (ostream &_s,set<_a> &_c){ return _OUTC(_s, ALL(_c)); }
template<typename _a, typename _b> ostream &operator << (ostream &_s, map<_a, _b> &_c){ return _OUTC(_s,ALL(_c)); }
template<typename _t> void pary(_t _a, _t _b){ _OUTC(cerr, _a, _b); cerr << endl; }
#define IOS
#else
#define wer(...)
#define pary(...)
#define IOS cin.tie(0); ios_base::sync_with_stdio(0);
#endif
// roy ya hahahahahahahahahahahahahaha

signed main() { IOS

}
