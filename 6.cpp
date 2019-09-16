#include <string>
#include <iostream>
using std::string;
using std::cout;
using std::endl;


#define MIN(a, b) (a) > (b) ? (b) : (a)

class Solution {
private:
    char *ret;
public:
    void Clear() {
        if (ret != nullptr)
            delete[] ret;
    }
    ~Solution() {
        Clear();
    }

    string convert(string s, int numRows) {
        int n = s.size();
        if (numRows < 2) return s; // 如果numRow = 1 直接返回即可
        ret = new char[n + 1]; // 末尾有一个\0
        int m = MIN(n, numRows);
        int idx = 0;
        
        for (int i = 0; i < m; i++) {
            //                      这里一定要注意 numRows - 1 = 0的情况
            for (int j = i; j < n; j += 2 * (numRows - 1)) {
                ret[idx++] = s[j];
                cout << "in" << endl;

                if (i > 0 && i < m - 1) { // 不是第一行和最后一行
                    cout << "进入内判断" << endl;
                    if (j + 2 * (numRows - 1 - i) < n)
                        ret[idx++] = s[j + 2 * (numRows - 1 - i)];
                }
            }
        }
        ret[idx] = '\0';
        return string(ret);
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    // cout << "PAYPALISHIRING->convert->" << s.convert("PAYPALISHIRING", 3) << endl;
    // cout << "PAYPALISHIRING->convert->" << s.convert("PAYPALISHIRING", 4) << endl;
    cout << "PAYPALISHIRING->convert->" << s.convert("A", 1) << endl;

    return 0;
}