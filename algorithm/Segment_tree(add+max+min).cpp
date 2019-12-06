// 區間加值
// 區間max min
// 初始化 init(0, maxn); 
// 區間加值 add(l, r, val);
// query_mx(l, r);
// query_mn(l, r);

const int maxn = 1e6 + 50;
namespace Segment_tree {
    int tag[maxn * 4] {};
    int mx[maxn * 4] {};
    int mn[maxn * 4] {};

    int L, R;

    void add(int ql, int qr, int val, int l = L, int r = R, int idx = 1) {
        assert(idx < maxn * 4 && idx >= 0);
        if(ql <= l && r <= qr) {
            tag[idx] += val;
            mx[idx] += val;
            mn[idx] += val;
            return;
        } 
        if(qr < l || r < ql) return;
        int mid = (l + r) >> 1;
        add(ql, qr, val, l, mid, idx << 1);
        add(ql, qr, val, mid + 1, r, idx << 1 | 1);
        mx[idx] = max(mx[idx << 1], mx[idx << 1 | 1]) + tag[idx];
        mn[idx] = min(mn[idx << 1], mn[idx << 1 | 1]) + tag[idx];
    }

    int query_mx(int ql, int qr, int l = L, int r = R, int idx = 1) {
        assert(idx < maxn * 4 && idx >= 0);
        if(ql <= l && r <= qr) return mx[idx];
        if(qr < l || r < ql) return -INT_MAX;

        int mid = (l + r) >> 1;
        int q1 = query_mx(ql, qr, l, mid, idx << 1);
        int q2 = query_mx(ql, qr, mid + 1, r, idx << 1 | 1);
        return max(q1, q2) + tag[idx];
    }

    int query_mn(int ql, int qr, int l = L, int r = R, int idx = 1) {
        assert(idx < maxn * 4 && idx >= 0);
        if(ql <= l && r <= qr) return mn[idx];
        if(qr < l || r < ql) return INT_MAX;

        int mid = (l + r) >> 1;
        int q1 = query_mn(ql, qr, l, mid, idx << 1);
        int q2 = query_mn(ql, qr, mid + 1, r, idx << 1 | 1);
        return min(q1, q2) + tag[idx];

    }


    void init(int l, int r, int val) {
        L = l, R = r;
        for(int i = l; i <= r; i++) {
            add(i, i, val);
        }
    }
    
}
using namespace Segment_tree;
