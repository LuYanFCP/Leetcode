#include <vector>
#include <iostream>
#include <unordered_map>
using std::vector;
using std::cout;
using std::endl;
using std::unordered_map;

class Solution {
public:
    /* 72 ms	229.3 MB	*/
    // vector<int> twoSum(vector<int>& nums, int target) {
    //     /* 有负数就比较麻烦 */
    //     // 首先求出 负数的最大值，最小值
        
    //     int min = ((unsigned)(-1))>>1; // 最小值定义为最大
    //     int max = ~min; // 最大值定义为最小 
        
    //     // 找到最大最小值
    //     for (int num : nums) {
    //         if (num > max)
    //             max = num;
    //         if (num < min)
    //             min = num;
    //     }

    //     int n = nums.size();
    //     vector<int> rs(2);
    //     // 确定hashTable的大小

    //     vector<int> hashTable(max - min + 1, -1);  // 这里太浪费了
        
    //     int currNum, diffNum, diffIdx;
    //     for (int i = 0; i < n; i++) {
    //         currNum = nums[i];
    //         diffNum = target - currNum;
    //         if (diffNum >= min && diffNum <= max) {
    //             diffIdx = diffNum - min;
    //             if (hashTable[diffIdx] != -1) { // 这也需要做相应的映射
    //                 rs[0] = hashTable[diffIdx];
    //                 rs[1] = i;
    //                 return rs;
    //             } else {
    //                     // 映射一下地址
    //                     hashTable[nums[i] - min] = i;
    //             }
    //         }
    //     }
    //     return rs;
    // }
    /*  240 ms	9.3 MB */
    // vector<int> twoSum(vector<int>& nums, int target) {
    //     vector<int> rs(2);
    //     for (int i = 1; i < nums.size(); i++) {
    //         for (int j = 0; j < i; j++) {
    //             if (nums[i] + nums[j] == target) {
    //                 rs[0] = j;
    //                 rs[1] = i;
    //             }
    //         }
    //     }
    //     return rs;
    // }
    /*8 ms 10.3 MB */
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> rs(2);
        int n = nums.size();
        unordered_map<int, int> hm;
        int currNum, diffNum;
        for (int i = 0; i < n; i++) {
            currNum = nums[i];
            diffNum = target - currNum;
            if (hm.find(diffNum) != hm.end()) { // 如果找到
                rs[0] = hm[diffNum];
                rs[1] = i;
            } else {
                hm[currNum] = i;
            }
        }
        return rs;
    }

};

int main()
{
    Solution s;
    vector<int> vec{-3, 4, 3, 90};
    vector<int> rs = s.twoSum(vec, 0);
    for (int i : rs)
        cout << i << ",";
    cout << endl;
}