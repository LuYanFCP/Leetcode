#include <vector>
#include <iostream>
#include <cassert>
using std::vector;
using std::cout;
using std::endl;
 // 小 大
#define min(a, b) (a) > (b) ? (b) : (a)
#define max(a, b) (a) > (b) ? (a) : (b)

class Solution {
public:
    int findkth(vector<int>& nums1, int begin1, vector<int>& nums2, int begin2, int k) { // find kth element {
        int n1 = nums1.size();
        int n2 = nums2.size();
        /* 递归停止条件 */
        if (begin1 >= n1)
            return nums2[begin2 + k - 1];
        if (begin2 >= n2)
            return nums1[begin1 + k - 1];

        if (k == 1)
            return min(nums1[begin1], nums2[begin2]);


        int midVal1 = begin1 + k/2 - 1 < n1 ? nums1[begin1 + k/2 - 1] : INT_MAX;
        int midVal2 = begin2 + k/2 - 1 < n2 ? nums2[begin2 + k/2 - 1] : INT_MAX; 
        if (midVal1 < midVal2)
            return findkth(nums1, begin1 + k/2, nums2, begin2, k - k/2);
        else
            return findkth(nums1, begin1, nums2, begin2 + k/2, k - k/2);
        

    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int k = (nums1.size() + nums2.size()) / 2;
        if ((nums1.size() + nums2.size()) % 2)
            return findkth(nums1, 0, nums2, 0, k + 1) * 1.0; 
        else 
            return (findkth(nums1, 0, nums2, 0, k) + findkth(nums1, 0, nums2, 0, k + 1)) * 1.0 / 2 ;
        
    }
        
        
        
        
        // /* 不需要判空 */
        // int len1 = nums1.size();
        // int len2 = nums2.size();
        
        // int start1 = 0, start2 = 0, end1 = len1 - 1 , end2 = len2 - 1;  // 指向两个的vector位置的指针 
        // int mid1, mid2;
        // int flag1 = true, flag2 = true;
        // while (flag1 && flag2) {// 条件待续
        //     mid1 = MID(start1, end1);
        //     mid2 = MID(start2, end2);
        //     cout << "nums1_mid:" << nums1[mid1] << endl;
        //     cout << "nums2_mid:" << nums2[mid2] << endl;
        //     if (nums1[mid1] > nums2[mid2]) {
        //         end1 = mid1 - 1;
        //         start2 = mid2 + 1;
        //     } else if (nums1[mid1] < nums2[mid2]) {
        //         start1 = mid1 + 1;
        //         end2 = mid2 - 1;
        //     } else {
        //         return nums1[mid1]; // 找到了
        //     }
        //     if (start1 > end1)
        //         flag1 = false;
        //     if (start2 > end2)
        //         flag2 = false;
        // }
        // // 只有一个是false的情况
        // if (!flag1) {
        //     cout << "flag1" << endl;
        //     if (end2 == start2) // 两个相等
        //         if ((len1 + len2) % 2) 
        //             return nums1[end1];
 
        //         return (nums1[end1] + nums2[start2]) / 2.0;
        //     if ((end2 - start2 + 1) % 2) {
        //         return (nums2[end2] + nums2[start2]) / 2.0;
        //     } else {
        //         return nums2[MID(start2, end2)] * 1.0;
        //     }
        // } else {
        //     cout << "flag2" << endl;
        //     if (end1 == start1) // 两个相等
        //         if ((len1 + len2) % 2) 
        //             return nums2[end2];
        //         return (nums2[end2] + nums1[start1]) / 2.0;
        //     if ((end1 - start1 + 1) % 2) {
        //         return (nums1[end1] + nums1[start1]) / 2.0;
        //     } else {
        //         return nums1[MID(start1, end1)] * 1.0;
        //     }
        // }

    
};


int main() {

    vector<int> v1{1, 2};
    vector<int> v2{3, 4};
    Solution s;

    cout << s.findMedianSortedArrays(v1, v2) << "<----result" << endl;
    // assert(2 == s.findMedianSortedArrays(v1, v2));

}