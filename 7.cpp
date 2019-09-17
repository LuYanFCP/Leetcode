#include <cmath>
#include <iostream>
#include <climits>
using std::abs;
using std::cout;
using std::endl;
// using std::MAX_INI;


class Solution {
public:
    int reverse(int x) {
        if (x == 0 || x == INT_MIN) // 因为int的范围[-2^31, 2^31 - 1],如果x == -2^31使用abs之后会溢出。 
            return 0;
        bool signal = x > 0; // 如果signal=true的时候为正数
        int x_abs = abs(x);
        int stack[32];
        int pos = -1;
        // 先全部入栈
        /*123456*/
        /*
         * div = 12345, mod = 6
         * div = 1234,  mod = 5
         * div = 123,   mod = 4
         * div = 12,  mod = 3
         * div = 1,  mod = 2
         * div = 0,  mod = 1          
         */

        int div = x_abs / 10, mod = x_abs % 10;
        while (div != 0 || mod != 0) { // 
            stack[++pos] = mod;
            mod = div % 10;
            div = div / 10;
        }
        long ans = 0, base = 1;
        while (pos != -1) {
            ans += base * stack[pos--];
            if (ans > INT_MAX) // 如果ans大于INT_MAX，则另一部分溢出
                return 0;
            base *= 10;
        }
        if (!signal) 
            ans *= -1;
        return ans;        
    }
};

int main() {
    Solution s;
    cout << s.reverse(123) << endl;
    cout << INT_MIN << endl;
}