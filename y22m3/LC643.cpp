//
// Created by 编程小北 on 2022/3/24.
//

#include <iostream>
#include <vector>


using namespace std;


double findMaxAverage(vector<int>& nums, int k);

// https://blog.csdn.net/weixin_33775582/article/details/90687476
// 学习笔记（一）省略std

// https://blog.csdn.net/wkq0825/article/details/82255984
// C++ vector的用法（整理）

// https://www.runoob.com/cplusplus/cpp-function-call-by-reference.html
// C++ 引用调用

// https://www.runoob.com/cplusplus/cpp-function-call-by-pointer.html
// C++ 指针调用

// https://www.runoob.com/cplusplus/cpp-function-call-by-value.html
// C++ 传值调用

// https://blog.csdn.net/qq_23415693/article/details/94459491
// C++的函数声明、函数定义、函数调用

// https://www.cnblogs.com/evenleee/p/10382335.html
// C++四种类型转换总结 const_cast static_cast dynamic_cast reinterpret_cast

//int main() {
//    std::cout << "Hello, World!" << std::endl;
//    int arr[] = {1,12,-5,-6,50,3};
//    vector<int> aaa(arr, arr + 6);
//    int k = 4;
//    double a = findMaxAverage(aaa, k);
//    return 0;
//}

double findMaxAverage(vector<int>& nums, int k) {

    int sum = 0;
    int n = nums.size();
    for (int i = 0; i < k; ++i) {
        sum += nums[i];
    }
    int  maxSum = sum;
    for (int i = k; i < n; ++i) {
        sum = sum - nums[i-k] + nums[i];
        maxSum = max(maxSum, sum);
    }

    return static_cast<double>(maxSum) / k;
}
