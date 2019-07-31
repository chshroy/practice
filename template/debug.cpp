/*
wer(a, b, ...)

- vector
werp(v)

- vector array
pary(all(v))
pary(a, a + 5)
*/
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
	_de(__VA_ARGS__, '\n');																	\
}
#define werp(v) if(1) {																	\
	cerr << __PRETTY_FUNCTION__ << " - " << __LINE__ << "(" << #v << ") = ";			\
	pary(v.begin(), v.end());															 				\
}
#else
#define wer(...)
#define werp(...)
#define pary(...)
#endif

