inline int min(int a, int b) {//最小值
    return a & ((a - b) >> 31) | b & ( ~ (a - b) >> 31);
}

/*Function to find minimum of x and y*/
inline int min(int x, int y) 
{ 
  return  y + ((x - y) & ((x - y) >> (sizeof(int) * CHAR_BIT - 1)));  
} 
  
/*Function to find maximum of x and y*/
inline int max(int x, int y) 
{ 
  return x - ((x - y) & ((x - y) >> (sizeof(int) * CHAR_BIT - 1))); 
} 
