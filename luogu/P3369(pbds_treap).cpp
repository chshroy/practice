// https://www.luogu.org/problemnew/show/P3369
// erase 好像是把全部的數字x刪掉，並非只刪一個，所以用map處理
// rank都是從0開始

#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;

typedef pair<int, int> ii;
#define rep(i, a, n) for(int i = a; i < n; ++i)
#define rep0(i, n) rep(i, 0, n)
#define rep1(i, n) rep(i, 1, n+1)
#define fs first
#define sc second

tree <ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> t;
map<int, int> mp;
/*
插入xx数
删除xx数(若有多个相同的数，因只删除一个)
查询xx数的排名(排名定义为比当前数小的数的个数+1+1。若有多个相同的数，因输出最小的排名)
查询排名为xx的数
求xx的前驱(前驱定义为小于xx，且最大的数)
求xx的后继(后继定义为大于xx，且最小的数)
*/

signed main() {
    int n;
    cin >> n;
    while(n--) {
        int k, in;
        cin >> k >> in;
        if(k == 1) t.insert({in, mp[in]++});
        else if(k == 2) t.erase({in, --mp[in]});
        else if(k == 3) cout << t.order_of_key({in, 0}) + 1 << endl;
        else if(k == 4) cout << t.find_by_order(in - 1) -> first << endl;
        else if(k == 5) {
            cout << (--t.lower_bound({in, 0})) -> first << endl;
        }
        else if(k == 6) cout << t.upper_bound({in, mp[in]}) -> first << endl; 
    }
}
