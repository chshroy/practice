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


// 位元運算加速技巧
// 1. 如果乘上一個 2 的倍數數值，可以改用左移運算(Left Shift) 加速 300
x = x << 6; 

// 2. 如果除上一個 2 的倍數數值，可以改用右移運算加速 350%
x = x >> 6;

// 3. 數值轉整數加速 10%
x = int(1.232)
//改為:
x = 1.232 >> 0;

// 4. 交換兩個數值(swap)，使用 XOR 可以加速 20%
swap(a, b)
//equals:
a ^= b;
b ^= a;
a ^= b;

// 5. 正負號轉換，可以加入 300%

i = -i;
//改為
i = ~i +1; // NOT 寫法
//或
i = (i ^-1)+1; // XOR 寫法

// 6. 取餘數，如果除數為 2 的倍數，可利用 AND 運算加速 600%

x = 131 % 4;
//equals:
x = 131 &(4-1);

// 7. 利用 AND 運算檢查整數是否為 2 的倍數，可以加速 600%

isEven = (i %2)==0;
//equals:
isEven = (i &1)==0;

//8. 加速 Math.abs 600% 的寫法1，寫法2 又比寫法1加速 20%

//寫法1
i = x < 0 ? -x : x;
//寫法2
i = (x ^ (x >> 31)) - (x >> 31);

// 9. 比較兩數值相乘之後是否擁有相同的符號，加速 35%

eqSign = a * b > 0;
//equals:
eqSign = a ^ b > 0;
