// https://www.luogu.org/problemnew/show/P1333
#include <bits/stdc++.h>
using namespace std;

// hash //////////////////////////////////
#include <bits/extc++.h>
using namespace __gnu_pbds;

gp_hash_table<string, int> mp; // O(n);
/////////////////////////////////////////

const int maxn = 250005;
int cnt[maxn];

struct DSU {
    int p[maxn], sz[maxn];
    
    void init() {
        for(int i = 0; i < maxn; ++i) p[i] = i, sz[i] = 1;
    }    
    
    int find(int x) {
        return x == p[x] ? x : p[x] = find(p[x]);
    }
    
    void uni(int x, int y) {
        // x, y must be parent
        x = find(x); y = find(y);
        if(x == y) return;
        if(sz[x] < sz[y]) swap(x, y);
        p[y] = x;
        sz[x] += sz[y];
    }
} dsu;

signed main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int tot = 0;
    string sa, sb;
    dsu.init();
    while(cin >> sa >> sb) {
        int a, b;
        if(mp.find(sa) == mp.end()) mp[sa] = tot++;
        if(mp.find(sb) == mp.end()) mp[sb] = tot++;
        a = mp[sa]; b = mp[sb];
        cnt[a]++; cnt[b]++;
        dsu.uni(a, b);
    }
    int odd = 0, f = dsu.find(0);
    for(int i = 0; i < tot; ++i) {
        if(cnt[i] % 2 == 1) odd++;
        if(dsu.find(i) != f) {
            cout << "Impossible\n";
            exit(0);
        }
    }
    if(odd <= 2) cout << "Possible\n";
    else cout << "Impossible\n";

}
