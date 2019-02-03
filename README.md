# Algorithms

### 8 旋转数组的最小值（查找与排序）

### 9 斐波那契数列（递归与循环）

1. 递归方法
```
long long Fibonacci(unsigned int n){
    if (n <= 0)
        return 0;
    if (n == 1)
        return 1;
    
    return Fibonacci(n-1) * Fibonacci(n-2);
}
```
分析：　

１）递归的本质是将问题分解成可重复的小问题，利用函数调用，以解决重复性。

２）但函数调用本身也需要时间和空间；每一次调用需要在内存栈中分配空间来保存参数、返回地址以及临时变量，这里入栈出栈也同样消耗时间。

３）递归有可能存在重复的部分，因为分解的小问题可能存在相互重叠部分，那么就存在重复计算。

４）递归调用层级如果超过栈的容量，会导致｀调用栈溢出｀问题。

对于斐波那契数列的上述解法，存在重复的计算。而且当ｎ越大，重复计算越大。这一块时间效率是可以提高的。


* 改进方法１：ｆｏｒ循环，时间复杂度O(n)
```
long long Fibonacci(unsigned int n)
{
    
    if (n<2)
        return n;
    long long add1 = 1;
    long long add2 = 0;
    long long sum = 0;
    for(unsigned int i=2; i<=n; ++i)
    {
        sum = add1 + add2;
        add2 = add1;
        add1 = sum;
    }
    return sum;
}
```
改进后，由于add1与add2在每次计算中起到暂存的作用，避免了重复计算。之前是随着n的增大，计算量n的指数方。现在为O(n)。空间复杂度也由O(ｎ)到O(1)。

* 装ｘ方法，时间复杂度O(logn)


* Ｆibonacci应用转化


### 10 二进制中１的个数（位运算）
* 解法思路：
* 方法1:相对位移（主定ｆｌａｇ动）
* 方法２：巧用位的加减法
