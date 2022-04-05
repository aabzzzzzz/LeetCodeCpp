//
// Created by 编程小北 on 2022/4/4.
//

#include "LC307.h"
#include <vector>
#include <iostream>

using namespace std;

class LC307 {
public:

    // 前缀和.
    vector<int> arr;
    vector<int> nums;

    LC307(vector<int>& nums) {
        nums = nums;
        arr[0] = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            arr[i] = arr[i-1] + nums[i];
        }
    }

    void update(int index, int val) {
        arr[index] =
    }

    int sumRange(int left, int right) {
        return arr[right] - arr[left];
    }

};


/**
 * 前缀和. 长度最小的子数组.
 * @param target
 * @param nums
 * @return
 */
int minSubArrayLen(int target, vector<int>& nums) {

    int n[nums.size()];
    for (int i = 0; i < nums.size(); ++i) {
        n[i] = n[i-1]+nums[i];
    }

    


}