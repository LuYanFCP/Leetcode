#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int empty[n+2], exist[n+2];
        exist[0] = INT_MIN;
        exist[1] = INT_MIN;
        empty[0] = 0;
        empty[1] = 0;
    
        for (int i = 0; i < n; ++i) {
            empty[i+2] = max(empty[i+1], exist[i+1] + prices[i]);
            exist[i+2] = max(exist[i+1], empty[i] - prices[i]);
        }
        return empty[n+1];
    }

    int maxProfit2(vector<int>& prices) {
        /**
         * 压缩之后的
        */
        int n = prices.size();
        int empty = 0, exist = INT_MIN, pre_empty = 0;
        int temp;
        for (int i = 0; i < n; ++i) {
            temp = empty;
            empty = max(temp, exist + prices[i]);
            exist = max(exist, pre_empty - prices[i]);
            pre_empty = temp;
        }
        return empty;
    }

};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> vec = {1,2,3,0,2};
    printf("%d", s.maxProfit(vec));
    return 0;
}
