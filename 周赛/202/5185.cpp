#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int i = 0, j = 0, count = 0;
        size_t n = arr.size();
        for (int j = 0; j < n; j++) {
            if (arr[j]%2) { // 如果是奇数
                count++;
                if (count==3) return true;
            } else {
                count = 0;
            }
        }
        return false;

    }
};