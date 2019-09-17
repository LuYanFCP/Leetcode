#include <iostream>
#include <string>
#include <vector>
#include <cassert>
using std::string;
using std::vector;
using std::cout;
using std::endl;

#define MIN(a, b) (a) > (b) ? (b) : (a)

class Solution {
/* 马拉车算法 */
private:
    char* ret = nullptr;

public:
    void Clear() {
        if (ret != nullptr)
            delete[] ret;
    }
    ~Solution() {
        Clear();
    }
    string preProcess(string s) {
        int n = s.size();
        if (n == 0) {
            return "^$";
        }
        ret = new char[2*n + 10];
        char* retP = ret;
        *retP = '^';
        for (int i = 0; i < n; i++) {
            *(++retP) = '#';
            *(++retP) = s[i];
        }
        *(++retP) = '#';
        *(++retP) = '$';
        *(++retP) = '\0';
        // cout << "pre:" << ret << endl;
        return string(ret); // 这该咋办
    }

    string longestPalindrome(string s) {
        string T = preProcess(s);
        int n = T.size();
        vector<int> P(n);
        int C = 0, R = 0; // C是中心，R是右半径
        for (int i = 1; i < n - 1; i++) {
            int i_mirror = 2 * C - i; // 找到i关于C的对称节点
            if (R > i) {  // 如果 i还在R的范围中，
                P[i] = MIN(R - i, P[i_mirror]);                    
            } else {
                P[i] = 0;
            }

            while (T[i + 1 + P[i]] == T[i - 1 - P[i]]) { // 中心拓展法
                P[i]++;
            }
            
            if (i + P[i] > R) { // 超出半径
                C = i; // 说明到i之前的C已经更新完成
                R = i + P[i]; // 半径扩大
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
