#include <string>

using std::string;

class Solution {
public:
    int myAtoi(string str) {
        int flag = -1; // 符号
        bool countDigit = false;
        long res = 0;
        for (char c : str) {
            if (c == ' ' && flag == -1)
                continue;
            if (c == '-' && flag == -1) {
                flag = 0;  // 负号
                continue;
            }
            if (c == '+' && flag == -1) {
                flag = 1;  // 正号
                continue;  
            }
            if (c >= '0' && c <= '9') {
                if (flag == -1) flag = 1; // 没有符号就是+
                countDigit = true; // 第一次出现数字
                res = res * 10 + (c - '0');
                if (INT_MAX < res && flag == 1)
                    return INT_MAX; // 超出边界
                if (flag == 0 && (-res) < INT_MIN)
                    return INT_MIN; // 超出边界

            } else if (!countDigit) {
                return 0;
            } else {
                return flag == 0 ? -res : (flag == 1 ? res : 0);
            }
        }
        return flag == 0 ? -res : (flag == 1 ? res : 0);            

    }
};