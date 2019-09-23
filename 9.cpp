class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        if (x == 0) return true;
        int stack[32];
        int pos = -1;
        /*
         *    div       mod
         *     12        1
         *     1         2
         *      0         1
         *      
         */
        int div = x / 10, mod = x % 10;
        while (div != 0||mod != 0) {
            stack[++pos] = mod;
            mod = div % 10;
            div = div / 10;
        }
        // 完成
        mod = x % 10, div = x / 10;
        while (pos != -1) {
            if (mod != stack[pos--]) {
                return false;
            }
            mod = div % 10;
            div = div / 10;
            
        }
        
        return true;
    }
};