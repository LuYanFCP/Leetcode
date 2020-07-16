class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int i = 0, j = n-1, mid;
        while(i < j) {
            mid = (j - i) / 2 + i;
            if (nums[mid] < target) {
                i = mid +　1;
            } else if (nums [mid] > target) {
                j = mid;
            } else {
                return mid;
            }
        }
        if (nums[i] < target) i++;
        return i;
    }
};