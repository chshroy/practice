// unsure if it is right

const int maxn = 2e5 + 50;
int bit[maxn];
inline int lowbit(int x){ return x& (-x); } 
void update(int x,int v){ 
    while(x <= maxn){ 
        bit[x] += v; x+=lowbit(x); 
    } 
} 
int sum(int x){ 
    int res = 0; 
    while(x){ 
        res += bit[x]; 
        x -= lowbit(x); 
    } 
    return res; 
}
