#include <vector>
#include <cstdio>
#include <algorithm>
#include <iterator>
#include <iostream>
using std::vector;
using std::partition_point;
using std::printf;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        if (nums.size() == 1)
            return nums[0];
        auto i = nums.begin();
        auto j = nums.end();
        auto begin = nums.begin();
        auto end = nums.end();

        // 题目不需要判断
        auto p_index = nums.begin() - 1;
        int mid_val = *i;
        int diff;


        while (i < j) {

            diff = end - p_index;
            if (diff > k) { // 偏前了
                i = p_index + 1;    // 去后面找
            } else if (diff < k) {
                j = p_index; // 容易出死循环
            } else {  // 相等
                // printf("diff: %d", diff);
                // return 0;
                return *p_index;
            }
            // mid_val = mid(*i, *(j-1), *((j - i) / 2 + i) );
            int mid_val = *i;
            // printf("{mid=%d}: ", mid_val);
            // printf("i=%d----", *i);
            p_index = partition(i+1, j, [mid_val](int a){return  a < mid_val;});  // 使用很麻烦
            p_index--;
            swap(*p_index, *i);
            // std::copy(begin, p_index, std::ostream_iterator<int>(std::cout, " "));
            // printf("*");
            // std::copy(p_index, end, std::ostream_iterator<int>(std::cout, " "));
            // printf(" p_index=%d", *p_index);
            // printf(" diff=%d\n", diff);

            // printf("===mid_val: {%d} ===\n", mid_val);

            // int debug;
            // std::cin >> debug;
        }
        return 0;
    }
    int mid(int a, int b, int c) {
        if (a > b)
            swap(a, b);
        if (b > c)
            swap(b, c);
        if (a > b)
            swap(a, b);
        return b;
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
    // vector<int> vec1 = {3,2,3,1,2,4,5,5,6};
    // printf("->%d \n", s.findKthLargest(vec1, 4));
    // vector<int> vec2 = {3,2,1,5,6,4};
    // printf("->%d \n", s.findKthLargest(vec2, 2));
    vector<int> vec3 = {2, 1};
    printf("->%d \n", s.findKthLargest(vec3, 2));
    // for (auto i : vec)
    //     printf("%d. \n", i);

    
}