typedef long long ll;
typedef pair<ll, ll> ii;

//prime factorization
vector<ii> get_fact(long long x){
	vector<ii> ret;
	for (ll i = 2; i*i <= x; i++){
		if (x % i) continue;
		int cnt = 0;
		while (x % i == 0){
			x /= i;
			cnt++;
		}
		ret.push_back({i,cnt});
	}
	if (x > 1) ret.push_back({x,1});
	return ret;
}
