//
// Created by 编程小北 on 2022/3/29.
//

#include "LC2024.h"
#include "LC2024.h"
#include <string>
#include <vector>

using namespace std;

/**
 * 2216. 美化数组的最少删除数
 * -> 把数组变为, nums[i] != nums[i + 1] 均成立
 * 这道题竟然可以用贪心做, nnd.
 */
//int minDeletion(vector<int>& nums) {
//    int ans = 0;
//    for (int i = 0; i < nums.size()-1; ++i) {
//        if (nums[i] == nums[i+1])ans++;//相同说明答案不满足, ans++;
//        else i++;//不相同说明满足跳两步.
//    }
//    if ((nums.size() - ans) % 2) ans++;
//    return ans;
//}


//bool searchMatrix(vector<vector<int>>& matrix, int target) {
//
//    int m = matrix.size();
//    int n = matrix[0].size();
//
//    int curM = 0;
//    int curN = n-1;
//
//    while (curM < m && curN > 0){
//        if (matrix[curM][curN] == target){
//            return true;
//        } else if (matrix[curM][curN] > target) {
//            curN--;
//        } else {
//            curM++;
//        }
//    }
//    return false;
//}


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    //前缀和. // 构建一个前缀和二叉树. 然后,
    int pathSum(TreeNode *root, int targetSum) {

    }
};


int maximalRectangle(vector<vector<char>> &matrix) {

    //最大矩形
}

/**
 * 二倍数对数组.
 * @param arr
 * @return
 */
bool canReorderDoubled(vector<int>& arr) {



}

