ll mdp(ll n,ll k) {
    ll rt = 1;
    n %= mod;
    while(k) {
      if(k&1) rt = rt * n % mod;
      n = n * n % mod;
      k >>= 1;
	  }
    return rt;
}
