//
// Created by 编程小北 on 2022/4/3.
//

#include <cmath>
#include "Offer001.h"

// 小心Math.abs(-2147483648)的坑
// https://www.cnblogs.com/zyf-yxm/p/13373377.html

// 位运算
// https://www.runoob.com/w3cnote/bit-operation.html


int divide(int a, int b) {
    // int 32位最大取值范围. 最大值 2^31-1
    // 最小值  -2^31
    //加一个判断条件.
    if (a == INT32_MIN && b == -1){
        // 如果除法结果溢出，则返回 2^31 − 1
        return INT32_MAX;
    }
    int sign = (a > 0) ^ (b > 0) ? -1 : 1;//默认是正数.
    if (a > 0){
        a = -a;
    }
    if (b > 0){
        b = -b;
    }
    int ans = 0;
    while(a >= b){
        a = a - b;
        ans ++;
    }
    return ans*sign;
}
