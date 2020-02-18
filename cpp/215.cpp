#include <vector>
#include <cstdio>
#include <algorithm>
using std::vector;
using std::partition;
using std::printf;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        if (nums.size() == 1)
            return nums[0];
        int i = 0;
        int j = nums.size() - 1;
        int len = nums.size(); // 末尾
        // 题目不需要判断
        int p_index = -1;
        while (i <= j) {
                      
            int diff = len - p_index; 
            if (diff > k) { // 偏前了
                i = p_index + 1;    // 去后面找
            } else if (diff < k) {
                j = p_index - 1;
            } else {  // 相等
                return nums[p_index];
            }
            p_index = partition(nums, i, j);
        }
        return 0;
    }
    int partition(vector<int>& nums, int begin, int end) {
        if (end == begin) {
            return begin;
        }
        int pivot = find_pivot_mid3(nums, begin, end);
        
        printf("\n [");
        for (auto i : nums)
            printf("%d, ", i);
        printf("]\n");
        int i = begin;
        int j = end - 1;
        while(1) {
            while (i < j && nums[i] < pivot) i++;
            while (i < j && nums[j] >= pivot) j--;
            if (i < j)  //如果满足则证明还没碰面
                swap(nums[i], nums[j]);
            else
                break;
        }
        swap(nums[i], nums[end-1]);
        printf("\n [");
        for (auto i : nums)
            printf("%d, ", i);
        printf("]\n");
        return i;
    }

    int find_pivot_mid3(vector<int>& nums, int begin, int end) {
        int mid = (end - begin) / 2 + begin;
        if (nums[mid] < nums[begin]) 
            swap(nums[mid], nums[begin]);
        if (nums[end] < nums[mid])
            swap(nums[end], nums[mid]);
        if (nums[mid] < nums[begin])
            swap(nums[mid], nums[begin]);

        swap(nums[mid], nums[end-1]);// 把中间值交换到后面
        return nums[end-1];
    }


    void swap(int& a, int& b) {
        int c = a;
        a = b;
        b = c;
    }

};

int main()
{
    Solution s;
    vector<int> vec = {3,2,1,5,6,4};
    printf("->%d \n", s.findKthLargest(vec, 2));
    for (auto i : vec)
        printf("%d. \n", i);
    
}