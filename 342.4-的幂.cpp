/*
 * @lc app=leetcode.cn id=342 lang=cpp
 *
 * [342] 4的幂
 */
class Solution {
public:
    bool isPowerOfFour(int x) {
        return (x > 0) && (x & (x - 1)) == 0 && (x - 1) % 3 == 0;
    }
};

