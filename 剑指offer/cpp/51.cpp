#include <vector>
#include <iterator>
#include <iostream>
using std::vector;

class Solution {
public:
    int reversePairs(vector<int>& nums) {
        temp = new int[nums.size()];
        return _reversePairs(nums, 0, nums.size()-1);
    }

    int _reversePairs(vector<int>& nums, int begin, int end) {

        if (begin < end) {
            int mid = (end - begin)/2 + begin;
            int left_rp = _reversePairs(nums, begin, mid);  // 已排好
            int right_rp = _reversePairs(nums, mid+1, end);
            // 两边执行完毕之后就已经是排好序了
            int i = begin, j = mid+1, k = begin;
            int grap_rp = 0;
            while (i <= mid && j <= end) {
                if (nums[i] <= nums[j]) {
                    temp[k++] = nums[i++];
                    grap_rp += j - mid - 1;
                } else {
                    //  nums[i] > nums[j]
                    temp[k++] = nums[j++];
                }
            }

            //  1 3 5 7 9 <= mid
            //  4 5 6 8 10
            // 
            while (i <= mid) {
                temp[k++] = nums[i++];
                grap_rp += j - mid - 1;   
            }
            while (j <= end) temp[k++] = nums[j++];
            std::copy(temp+begin, temp+end+1, nums.begin()+begin);
            // std::copy(temp+begin, temp+end+1, std::ostream_iterator<int>(std::cout, " "));
            // std::cout << std::endl;
            // std::cout << "left_rp: " << left_rp << " right_rp: " << right_rp << " grap_rp: " << grap_rp << endl;
            return left_rp + right_rp + grap_rp;
        } else {
            return 0;
        } 

    }
private:
    int *temp;
};