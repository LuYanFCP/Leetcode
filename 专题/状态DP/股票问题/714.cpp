#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        int empty = 0, exist = -1000000, temp;    // exist 改成这个是防止 exist + prices[i] - fee 溢出
        for (int i = 0; i < n; ++i) {
            temp = empty;
            empty = max(empty, exist + prices[i] - fee);
            exist = max(exist, temp - prices[i]);
        }
        return empty;
    }
};