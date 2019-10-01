/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

// @lc code=start
class Solution {
public:
    string longestPalindrome(string s) {
        
        int n = s.size();
        if (n == 0) return "";
        string ret = "";
        int st, ed;

        int ans = 0;

        for (int i = 0; i < n; ++i){
            int x = i, y = i;

            while (x >= 0 && y < n){
                if (y - x + 1 > ans){
                    ans = y - x + 1;
                    st = x;
                    ed = y;
                }
                --x;
                ++y;
                
                if (x < 0 || y >= n) break;
                if (s[x] != s[y]) break;             
            }
        }

        for (int i = 0; i < n - 1; ++i){
            int x = i, y = i + 1;
            if (s[x] != s[y]) continue;
        
            while (x >= 0 && y < n){
                if (y - x + 1 > ans){
                    ans = y - x + 1;
                    st = x;
                    ed = y;
                }
                --x;
                ++y;
                if (x < 0 || y >= n) break;
                if (s[x] != s[y]) break;
                
                if (y - x + 1 > ans){
                    ans = y - x + 1;
                    st = x;
                    ed = y;
                }
            }   
        }

        return s.substr(st, ed - st + 1);
    }
};
// @lc code=end

