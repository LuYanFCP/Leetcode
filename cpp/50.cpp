#include <climits>
#include <cmath>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        /**
         * 用时: 4ms
         * 内存: 5.9MB
         */
        // printf("%d", INT_MIN);
        bool flag = false;
        if (n < 0) {
            if (n != INT_MIN)
                n = -n;
            else {
                n = -(n+1);
                flag = true;
            }
            x = 1/x;
        }
        double base = x;
        double res = 1.0;
        for (;n; n = n >> 1, base *= base) {
            if (n % 2) {
                res *= base;
            }
        }
        if (flag)
            res *= x;
        return res;
    }
    double myPow2(double x, int n) {
        /*优化*/
        /**
         * 用时: 0ms
         * 内存: 6MB
        */
        if (n == 1.0) return 1.0;
        if (n < 0) x = 1/x;
        unsigned int m = abs(n);   // 取代了复杂的变换
        double res = 1.0;
        double base = x;
        for (; m; m = m>>1, base *= base) 
            if (m%2) res *= base;
        return res;
    }

};