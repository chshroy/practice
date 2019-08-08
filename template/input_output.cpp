/*
re(a, b, c, ..)
ou(a, b, c, ..)

- vector
re_v(n, v)
ou_v(v)
*/

namespace input {
	template<typename T> void re(T&& t) { cin >> t; }
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
	void re(T&& t, Args&&... args) { re(t); re(args...); }
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

