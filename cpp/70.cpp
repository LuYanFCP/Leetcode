class Solution {
public:
    int climbStairs(int n) {
        int a = 1;
        int b = 1;
        int temp;
        for (int i = 2; i <= n; ++i) {
            temp = b;
            b = a + b;
            a = temp;
        }
        return b;
    }
};