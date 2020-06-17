#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& A) {
        int n = A.size();
        int max_score = 0;
        int pre = A[0] + 0, ans = 0;
        for (int j = 1; j < n; j++) {
            ans = max(ans, pre + A[j] - j);
            pre = max(pre, A[j]+j);
        }
        return ans;
    }
};