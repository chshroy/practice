// https://www.luogu.org/problemnew/show/P1282
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> ii;
#define rep(i, a, n) for(int i = a; i < n; ++i)
#define rep0(i, n) rep(i, 0, n)
#define rep1(i, n) rep(i, 1, n+1)
#define fs first
#define sc second
#define pb push_back
#define endl '\n' 

const int maxn  = 1e6;
int w[maxn], v[maxn], turn, ask, d[maxn];

//找很久的bug: 翻出4 可能比翻出2簡單  
signed main() {
    int n;
    cin >> n;
    rep0(i, n) {
        int a, b;
        cin >> a >> b;
        if(a == b) continue;
        if(a > b) {
            turn ++;
            v[i] = -1;
            w[i] = (a - b) * 2;
            ask += (a - b);
        } 
        else {
            v[i] = 1;
            w[i] = (b - a) * 2;
            ask += (b - a);
        }
    }
    memset(d, 0x3f, sizeof(d));
    d[0] = turn;
    rep0(j, n) for(int i = ask * 2; i >= w[j]; --i) {
        d[i] = min(d[i], d[i-w[j]] + v[j]);
    }
    for(int i = ask, j = ask; i >= 0; i--, j++) //要記得同時往上和往下找 
        if(d[i] <= n || d[j] <= n) {
            cout << min(d[i], d[j]) << endl;
            break;
        }
}
