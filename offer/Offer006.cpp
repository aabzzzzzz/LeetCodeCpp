//
// Created by 编程小北 on 2022/4/5.
//

#include "Offer006.h"

#include <vector>
#include <string>

using namespace std;


vector<int> twoSum(vector<int> &numbers, int target) {
    int leftIndex = 0;
    int rightIndex = numbers.size() - 1;
    while (leftIndex < rightIndex) {
        if (numbers[leftIndex] + numbers[rightIndex] > target) {
            rightIndex--;
        } else if (numbers[leftIndex] + numbers[rightIndex] < target) {
            leftIndex++;
        } else {
            return {leftIndex, rightIndex};
        }
    }
    return {};
}


vector<vector<int>> threeSum(vector<int> &nums) {


    int n = nums.size();
    // if(n == 0)return{};
    sort(nums.begin(), nums.end());

    vector<vector<int>> ans;

    // 相对于原有的排序, 加一个题解,
    for (int i = 0; i < n - 2; ++i) {
        if (nums[i] > 0) break;
        if (i > 0 && nums[i] == nums[i - 1]) continue;
        int leftIndex = i + 1;
        int rightIndex = n - 1;

        while (leftIndex < rightIndex) {

            int sum = nums[i] + nums[leftIndex] + nums[rightIndex];

            if (sum > 0) {
                rightIndex--;
                while (leftIndex < rightIndex && nums[rightIndex] == nums[rightIndex + 1]) {
                    rightIndex--;
                }
            } else if (sum < 0) {
                leftIndex++;
                while (leftIndex < rightIndex && nums[leftIndex] == nums[leftIndex - 1]) {
                    leftIndex++;
                }
            } else {
                ans.push_back({nums[i], nums[leftIndex], nums[rightIndex]});
                rightIndex--;
                while (leftIndex < rightIndex && nums[rightIndex] == nums[rightIndex + 1]) {
                    rightIndex--;
                }
                leftIndex++;
                while (leftIndex < rightIndex && nums[leftIndex] == nums[leftIndex - 1]) {
                    leftIndex++;
                }
            }
        }

    }

    return ans;
}

/*
 * s2 包含 s1
 */
bool checkInclusion(string s1, string s2) {
    int n = s1.size();
    int m = s2.size();

    if (n > m) {
        return false;
    }

    vector<int> arr1(26, 0);
    vector<int> arr2(26, 0);

    for (int i = 0; i < n; i++) {
        arr1[s1[i] - 'a']++;
        arr2[s2[i] - 'a']++;
    }

    if (arr1 == arr2) {
        return true;
    }

    for (int i = n; i < m; i++) {

        arr2[s2[i] - 'a']++;
        arr2[s2[i - n] - 'a']--;

        if (arr1 == arr2) {
            return true;
        }
    }

    return false;
}


/**
 * 验证 s 是否是 回文串
 * @param s
 * @return
 */
bool isPalindrome(string s) {
    int i = 0;
    int j = s.size() - 1;
    while (i < j) {
        if (!isalnum(s[i])) {
            i++;
        } else if (!isalnum(s[j])) {
            j--;
        } else {
            if (tolower(s[i]) != tolower(s[j])) {
                return false;
            } else {
                i++;
                j--;
            }
        }
    }
    return true;
}

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *removeNthFromEnd(ListNode *head, int n) {

    ListNode* dummy = new ListNode(0, head);
    ListNode* first = head;
    ListNode* second = dummy;
    for (int i = 0; i < n; ++i) {
        first = first->next;
    }
    while (first) {
        first = first->next;
        second = second->next;
    }
    second->next = second->next->next;
    ListNode* ans = dummy->next;
    delete dummy;
    return ans;
}



