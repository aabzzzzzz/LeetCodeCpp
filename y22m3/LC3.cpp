//
// Created by 编程小北 on 2022/3/25.
//

#include <iostream>
#include "LC3.h"
#include "string"
#include "unordered_map"
#include <vector>

using namespace std;

// https://blog.csdn.net/liitdar/article/details/80498634
// C++中的string类用法简介

// https://blog.csdn.net/u012604810/article/details/79798082
// c++ unordered_map 判断某个键是否存在

// http://c.biancheng.net/view/7231.html
// C++ STL unordered_map容器用法详解

// https://www.cnblogs.com/jiaxinli/p/13330621.html
// unordered_set的用法

// https://www.cnblogs.com/narjaja/p/10039509.html
// emplace与insert的区别（C++11）

// https://blog.csdn.net/weixin_43347376/article/details/116350269
// CLion错误wchar .h not found解决方案

// http://m.biancheng.net/view/7237.html
// C++ STL unordered_map获取元素的4种方法（超级详细）


int lengthOfLongestSubstring(string s) {

    int left = 0;
    int right = 0;
    int result = 0;

    unordered_map<char, int> window;//c++ 初始化对象 不需要new. 声明即可.

    for (int i = 0; i < s.size(); ++i) {

        char c = s[i];

        if (window.count(c)){//如果有, 就是返回1, c++ 中, 1 可以用来当做判断条件的值.
            int index = window[c];
            left = max(left, index+1);
        }

        window[c] = i;//c++ 的map中, 不必用put. 添加, 直接赋值即可. so easy.(类似于java数组那样就行.奇奇怪怪)
        right++;
        result = max(result, right- left);
    }

    return result;
}


int minSubArrayLen(int target, vector<int>& nums) {


    int left = 0;
    int right = 0;
    int result = INT_MAX;

    int n = nums.size();
    if (n == 0){
        return 0;
    }
    int sum = 0;

    while (right < n){
        sum+= nums[right];
        while (sum >= target){
            result = min(result, right- left + 1);
            sum -= nums[left];
            left++;
        }
        right++;
    }
    return result == INT_MAX ? 0: result;

}

int main() {
    std::cout << "Hello, World!" << std::endl;
    lengthOfLongestSubstring("abcabcbb");
    return 0;
}


