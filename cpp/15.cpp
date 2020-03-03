#include <vector>
#include <algorithm>
#include <iterator>
#include <iostream>
using std::vector;
using std::sort;
using std::cout;
using std::ostream_iterator;


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int i = 0;
        int j = nums.size() - 1;
        int k;
        int pos;
        vector<vector<int>> rs;
        int diff;
        while (i < j) { // {-4, -1, -1, 0, 1, 2}
            diff = 0 - nums[i] - nums[j]; 
            if (diff > nums[j] || diff < nums[i]) {
            } else {
                pos = b_search(nums, i+1, j-1, diff);
                if (pos == -1) {
                   
                } else {
                    rs.push_back(vector<int>{nums[i], nums[pos], nums[j]});
                }
            }

            if (diff > 0) 
                i++;
            else 
                j--;
        }
        return rs;
    }
    int b_search(vector<int>& nums, int i, int j, int target) {
        int mid;
        int mid_val;
        while (i < j) {
            mid = (j - i) / 2 + i;
            mid_val = nums[mid];
            if (mid_val > target) {
                j = mid - 1;
            } else if (mid_val < target) {
                i = mid + 1;
            } else {
                return mid;
            }
        }
        if (nums[i] == mid_val)
            return i;
        
        return -1;
    }
};

int main()
{
    Solution s;
    vector<int> vec = {-1, 0, 1, 2, -1, -4};
    auto res = s.threeSum(vec);
    for (auto r: res) {
        std::copy(r.begin(), r.end(), ostream_iterator<int>(cout, " "));
        cout << std::endl;
    }
}

