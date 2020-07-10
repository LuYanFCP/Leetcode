#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int empty[n+1], exist[n+1];
        empty[0] = 0;
        exist[0] = INT_MIN;
        for (int i = 0; i < n; ++i) {
            empty[i+1] = max(empty[i], exist[i] + prices[i]);
            exist[i+1] = max(exist[i], empty[i] - prices[i]);
        }
        return empty[n];
    }
    int maxProfit2(vector<int>& prices) {
        int n = prices.size();
        int empty = 0, exist = INT_MIN, temp;   
        for (int i = 0; i < n; ++i) {
            temp = empty;
            empty = max(empty, exist + prices[i]);
            exist = max(exist, temp - prices[i]);
        }
        return empty;
    }
};