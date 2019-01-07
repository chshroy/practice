//RMQ Sparse table
#define p2(i) (1<<(i))

void build_RMQ() {  //build RMQ from a array
	rep0(i,n) rm[i][0] = a[i];
	rep1(k,__lg(n))
		for(int i=0;i<=n-p2(k);i++) 
			rm[i][k] = min(rm[i][k-1],rm[i+p2(k-1)][k-1]);
}

int query(int l, int r) {
	int k = __lg(r-l+1);
	return min(rm[l][k], rm[r-p2(k)+1][k]);
}
