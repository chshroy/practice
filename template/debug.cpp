/*
wer(a, b, ...)
- vector
werp(v)
*/
namespace DEBUG {
	template<typename T> void _de(const T& t) { cerr << t; }
	template<typename T1, typename T2>									// pair
	void _de(const pair<T1, T2> &t) { cerr << '(' << t.first << ", " << t.second << ')'; }

	template<typename T>
	void _dev(T t1, T t2) {
		_de(*t1);
		if(t1 != t2) _de(", "),_dev(++t1, t2);
	}

	template<typename T, typename... Args>
	void _de(const T& t, const Args&... args) { cerr << t << ' '; _de(args...); }
}

#ifdef rrr
using namespace DEBUG;
#define wer(...) if(1) {																\
	cerr << __PRETTY_FUNCTION__ << " - " << __LINE__ << "(" << #__VA_ARGS__ << ") = ";	\
	_de(__VA_ARGS__);																	\
}
#define werp(v) if(1) {																	\
	cerr << __PRETTY_FUNCTION__ << " - " << __LINE__ << "(" << #v << ") = [";	\
	_dev(v.begin(), v.end() - 1); cerr << "]\n";															 				\
}
#else
#define wer(...)
#define werp(v)
#endif
