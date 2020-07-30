class Solution {
public:
    int findMagicIndex(vector<int>& nums) {
        return find(nums, 0, nums.size()-1);
       
    }
    int find(vector<int>& nums, int l, int r) {
        int mid, res;
        // printf("%d, %d\n", l, r);
        while (l < r) {
            mid = (l+r)/2;
            // printf("mid:%d\n", mid);
            if (nums[mid] == mid) { //如果找到，找前一半
                // printf("ok mid-> %d\n", mid);

                res = find(nums, l, mid-1);
                // printf("result: %d\n", res);
                return res == -1 ? mid:res;
            } else {
                res = find(nums, l, mid-1);
                if (res == -1) res = find(nums, mid+1, r);
                return res;
            }
        }
        return nums[l] == l? l:-1;
    }
};