/*input

*/
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

#define int long long

using ii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;
using Treap =  tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;

#define for_(i, a, n) for(int i = a; i < n; ++i)
#define for_r(i, n) for(int i = n - 1; i >= 0; ++i)
#define for_0(i, n) for_(i, 0, n)
#define for_1(i, n) for_(i, 1, n + 1)

#define SZ(a) (int)a.size()
#define ALL(a) a.begin(),a.end()
#define PI acos(-1.0)
#define fs first
#define sc second
#define pb push_back
#define eb emplace_back
#define endl '\n'
#define INF INT_MAX
#define CASET int ___T; cin >> ___T; for_1(cs, ___T)

template<class T> void _W(const T &x) { cout << x; }
template<class T, class U> void _W(const pair<T, U> &x) { _W(x.fs); putchar(' '); _W(x.sc);}
template<class T> void _W(const vector<T> &x) { for (auto i = x.begin(); i != x.end(); _W(*i++)) if (i != x.cbegin()) putchar(' '); }

#ifdef rrr
#define wer(...) if(1) {															    \
    fprintf(stderr, "%s - %d (%s) = ", __PRETTY_FUNCTION__, __LINE__, #__VA_ARGS__);    \
    _do(__VA_ARGS__);																    \
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

/* 多筆測資 
CASET {
	cout << cs << endl;
}
*/
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

signed main() {

}
