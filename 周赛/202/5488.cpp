#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int minOperations(int n) {
        int mid_val, mid_pos;
        if (n%2) { // 基数
            mid_pos = n/2;
            mid_val = mid_pos*2+1;
        } else {
            mid_pos = n/2;
            mid_val = mid_pos*2;
        }
        int ans = 0;
        for (int i = 0; i < mid_pos; ++i) {
            ans += (mid_val - (2*i+1));
        }
        return ans;
    }
};