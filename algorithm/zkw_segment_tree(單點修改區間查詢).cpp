// 正確性不明
const int maxn = 1e5+50;
const int M = 131071; // 1048576 / 8 - 1

struct seg_tree {
	
	int t[M * 2];
	// 單點加值 
	void modify_1(int x, int val) {
		for(x += M; x; x >>= 1) t[x] += val;
	}
	
	//區間查詢(區間和) 
	int query(int l, int r) {
		int rt = 0;
		for(l += M - 1, r += M + 1; l ^ r ^ 1; l >>= 1, r >>= 1) {
			// l ^ r ^ 1父節點一樣就停止
			if(~l&1) rt += t[l^1]; //l % 2 == 0
    		if(r&1) rt += t[r^1]; // r % 2 == 1 
		}
		return rt;
	}
} tree;
//modify_1(1, 5) 將第一個點加5 *注意沒有第零個點 
// query(l, r) 查詢 l ~ r的區間和 
