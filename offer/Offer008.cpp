//
// Created by 编程小北 on 2022/4/4.
//

#include "Offer008.h"
#include <vector>

using namespace std;

/**
 * 和大于等于 target 的最短子数组
 * @param target
 * @param nums
 * @return
 */
int minSubArrayLen(int target, vector<int>& nums) {
    //0. 常规判断.
    int n = nums.size();
    if (n == 0){
        return n;
    }

    /**
     * 采用前缀和的写法. + 二分查找.
     *
     */

    //1. 生成前缀和数组.
    vector<int> sums(n+1, 0);
    for (int i = 1; i <= n; ++i) {
        sums[i] = sums[i-1]+nums[i-1];
    }

    //2.

}


/**
 * 二分查找, (大于等于target)
 * @param nums
 * @param l
 * @param right
 * @param target
 * @return
 */
int binarySearch(vector<int>& nums, int l, int r, int target){

    int mid = -1, curLeft = l, curRight = r;

    while (curLeft <= curRight){
        mid = (curLeft+curRight) >> 1;
        if (nums[mid] < target){
            curLeft = mid+1;
        } else {
            curRight = mid;
        }
    }

    return (nums[curLeft] > target) ? curLeft : -1;

}

int search(vector<int>& nums, int target) {

    int left = 0;
    int right = nums.size()-1;

    while (left <= right){
        int mid = (left+right)/2;

        if (nums[mid] < target){
            left = mid+1;
        } else if (nums[mid] > target){
            right = mid-1;
        } else {
            return mid;
        }
    }

    return -1;
}

/**
 * 查找插入位置
 * @param nums
 * @param target
 * @return
 */
int searchInsert(vector<int>& nums, int target) {

    int left = 0;
    int right = nums.size()-1;

    while (left <= right){
        int mid = (left+right)/2;
        if (nums[mid] < target){
            left = mid+1;
        } else if (nums[mid] > target){
            right = mid-1;
        } else {
            return mid;
        }
    }

    return left;
}

/**
 * 数组一定是奇数组
 * 所以 -> mid 有可能是奇数, 有可能是偶数.
 * [1,1,2,3,3]
 *  [3,3,7,7,10]
 * mid 是偶数 ->
 *      判断是否跟 mid+1 相等
 * mid 是奇数 ->
 *      判断是否跟 mid-1 相等
 * @param nums
 * @return
 */
int singleNonDuplicate(vector<int>& nums) {

    int left = 0;
    int right = nums.size()-1;

    while (left <= right){
        int mid = (left+right)>>1;
        if (mid % 2 == 0){
            //偶数.
            if (nums[mid] == nums[mid+1]){
                left = mid+1;
            } else {
                right = mid-1;
            }
        } else {
            //奇数.
            if (nums[mid] == nums[mid-1]){
                left = mid+1;
            } else {
                right = mid-1;
            }
        }
    }


    return nums[left];
}

