#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int end = *max_element(nums.cbegin(), nums.cend());
        int begin = 1;
        int mid, _sum, res = -1;
        while (end > begin) {
            mid = (end - begin)/2 + begin;
            _sum = 0;
            for (int num: nums) {
                _sum += (num - 1 + mid)/mid;
            }

            if (_sum > threshold) {
                begin = mid+1;
            } else {
                end = mid;
            }
        }
        return end;

    }


};