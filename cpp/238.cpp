#include <vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 1);
        int pre = 1, post = 1;
        for (int i = 1, j = n-1; i < n; ++i) {
            res[i] *= pre;
            res[j] *= post;
            pre *= res[i];
            post *= res[j];
        } // 正着求
        return res;
    }
};