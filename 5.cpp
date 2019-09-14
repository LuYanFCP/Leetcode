#include <iostream>
#include <string>
#include <vector>
#include <cassert>
using std::string;
using std::vector;
using std::cout;
using std::endl;

#define MIN(a, b) (a) > (b) ? (b) : (a)

string preProcess(string s) {
    int n = s.size();
    if (n == 0) {
        return "^$";
    }
    string ret = "^";
    for (int i = 0; i < n; i++)
        ret = ret + "#" + s[i];
    ret += "#$";
    return ret;
}


class Solution {
/* 马拉车算法 */
public:
    string longestPalindrome(string s) {
        string T = preProcess(s);
        int n = T.size();
        vector<int> P(n);
        int C = 0, R = 0;
        for (int i = 1; i < n - 1; i++) {
            int i_mirror = 2 * C - i;
            if (R > i) {
                P[i] = MIN(R - i, P[i_mirror]);
            } else {
                P[i] = 0;
            }

            while (T[i + 1 + P[i]] == T[i - 1 - P[i]]) {
                P[i]++;
            }
            
            if (i + P[i] > R) {
                C = i;
                R = i + P[i];
            }
        }

        int maxLen = 0;
        int centerIndex = 0;
        for (int i = 1; i < n - 1; i++) {
            if (P[i] > maxLen) {
                maxLen = P[i];
                centerIndex = i;
            }

        }
        int start = (centerIndex - maxLen) / 2;
        return s.substr(start, maxLen); // 这里一定要注意C++的API与Java不同
    }
};


int main()
{
    Solution s;
    cout << s.longestPalindrome("babad") << endl;


}