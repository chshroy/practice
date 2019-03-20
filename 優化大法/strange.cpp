inline int min(int a, int b) {//最小值
    return a & ((a - b) >> 31) | b & ( ~ (a - b) >> 31);
}
