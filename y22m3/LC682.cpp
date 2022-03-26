//
// Created by 编程小北 on 2022/3/26.
//

#include "LC682.h"
#include <string>
#include <stack>
#include <vector>

// https://blog.csdn.net/qq_34861505/article/details/111378323
// C++中#include＜＞和#include““的区别

int squareSum(int slow);

using namespace std;



int main(){

    return 0;
}

int arraySign(vector<int>& nums) {

    int product = 1;
    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] < 0){
            product *= -1;
        } else if (nums[i] > 0){
            product *= 1;
        } else {
            return 0;
        }
    }

    return product;
}

bool areAlmostEqual(string s1, string s2) {

    int n = s1.size();
    int no = 0;
    for (int i = 0; i < n; ++i) {
        if (s1[i] != s2[i]){
            no++;
            if (no <2){
                return false;
            }
        }
    }
    return true;
}

bool isHappy(int n) {

    int fast = n;
    int slow = n;
    do {
        slow = squareSum(slow);
        fast = squareSum(fast);
        fast = squareSum(fast);
    } while (slow != fast);

    if (fast == 1){
        return true;
    } else {
        return false;
    }
}

int squareSum(int number) {

    int squareSum = 0;
    while (number != 0){
        squareSum = number%10 * number%10;
        number /= 10;
    }
    return squareSum;
}

bool canMakeArithmeticProgression(vector<int>& arr) {
    if (arr.size() <= 2) return true;
    sort(arr.begin(), arr.end());
    int cur = arr[1] - arr[0];
    for (int i = 1; i < arr.size() - 1; ++i) {
        if (arr[i+1] - arr[i] != cur) return false;
    }
    return true;
}

int calPoints(vector<string>& ops) {
    int res = 0;
    stack<int> s;
    for (int i = 0; i < ops.size(); ++i) {
        if (ops[i] == "+") {
            int a = s.top();
            s.pop();
            int b = s.top();
            s.push(a);
            s.push(a  + b);
        } else if (ops[i] == "D") {
            int a = s.top();
            s.push(2 * a);
        } else if (ops[i] == "C") {
            s.pop();
        } else {
            s.push(stoi(ops[i]));
        }
    }
    while (!s.empty()) {
        res += s.top();
        s.pop();
    }
    return res;
}