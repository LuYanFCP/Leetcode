#include <vector>
#include <unordered_set>
#include <algorithm>
#include <iterator>
#include <iostream>
using std::vector;
using std::sort;
using std::cout;
using std::ostream_iterator;
using std::unordered_set;
using std::swap;


struct my_vector_hash {
    std::size_t operator() (vector<int> const &vec) const {
        std::size_t seed = vec.size();
        for (auto &i : vec) {
            seed ^= i + 0x9e3779b9 + (seed << 6) + (seed >> 2);
        }
        return seed;
    }
};

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        // [0,0,0,0]
        // [1,-1,-1,0]
        unordered_set<vector<int>, my_vector_hash> res;
        if (nums.size() < 3)
            return vector<vector<int>>();
        unordered_set<int> hashtable;
        int diff;
        int len = nums.size();
        for (int i = 0; i < len - 2; ++i) {
            
            diff = 0 - nums[i];
            // 固定一个值转化为 two sum问题
            for (int j = i + 1; j < len; ++j) {
                /* 加强版two sum
                 * x 可重复
                 */
                int target_val_k = diff - nums[j];
                if (hashtable.find(target_val_k) != hashtable.end()) {
                    res.insert(sort_seq(nums[i], nums[j], target_val_k));
                } else {
                    hashtable.insert(nums[j]);
                }
            }
            hashtable.clear();
        }
        vector<vector<int>> res_vec;
        res_vec.assign(res.begin(), res.end());
        return res_vec;
    }
    vector<int> sort_seq(int i, int j, int k) {
        if (i > j)
            swap(i, j);
        if (j > k)
            swap(j, k);
        if (i > j)
            swap(i, j);
        return vector<int> {i, j, k};
    }
};

class Solution2 {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
    /**
     * Runtime: 92 ms, faster than 94.37% 
     * Memory Usage: 13.6 MB, less than 100.00%
    */
        vector<vector<int>> res;
        int len = nums.size();
        if (len < 3)
            return res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < len - 2; ++i) {
            if (i > 0 && nums[i] == nums [i-1])
                continue;
            int l = i + 1;
            int r = len - 1;

            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];

                if (sum < 0) {
                    ++l;
                } else if (sum > 0) {
                    --r;
                } else {
                    res.push_back(vector<int> {nums[i], nums[l], nums[r]});
                    while (l < r && nums[l] == nums[l+1]) {
                        ++l;
                    }
                    
                    while (l < r && nums[r] == nums[r-1]) {
                        --r;
                    }
                    // 向后移动指针
                    ++l;
                    --r;
                }
            }

        }
        return res;
    }
       
};



//     vector<vector<int>> threeSum(vector<int>& nums) {
//         vector<vector<int>> rs;
//         if (nums.size() < 3)
//             return rs;
//         sort(nums.begin(), nums.end());
//         int i = 0;
//         int j = nums.size() - 1;
//         int k;
//         int pos, diff;
//         while (i + 1 < j) { // {-4, -1, -1, 0, 1, 2}
//             diff = 0 - nums[i] - nums[j]; 
//             pos = b_search(nums, i+1, j-1, diff);
//             // printf("i=%d, j=%d ----- nums[i]=%d, nums[j]=%d\n", i, j, nums[i], nums[j]);

//             if (diff <= nums[j] && diff >= nums[i] && pos != -1) {
//                 // printf("test1\n");
//                 rs.push_back(vector<int>{nums[i], nums[pos], nums[j]});
//                 int r = nums[j] - nums[j-1], l = nums[i+1] - nums[i];
//                 if (r == 0 || l == 0) {
//                     while (r == 0 && i + 1 < j) {
//                         j--;
//                         r = nums[j] - nums[j-1];
//                     }
                    
//                     while (l == 0 && i + 1 < j) {
//                         i++;
//                         l = nums[i+1] - nums[i];
//                         // printf("i=%d\n", i);                                
//                     }
//                     if (i + 1 < j)
//                         break;

//                 }
                
//                     if (r > l) {  // 判断谁离下一个更近
//                         i++;
//                     } else if (r < l) {
//                         j--;
//                     } else {
//                         i++;
//                         j--;
//                     }    
                
                
//                 // printf("test2\n");
//             } else {                    
//                 if (diff >= 0) 
//                     i++;
//                 else 
//                     j--;
//             }
//                                 // printf("i=%d, j=%d\n", i, j);

//         }
//         return rs;
//     }
//     int b_search(vector<int>& nums, int i, int j, int target) {
//         int mid;
//         int mid_val;
//         while (i < j) {
//             mid = (j - i) / 2 + i;
//             mid_val = nums[mid];
//             if (mid_val > target) {
//                 j = mid - 1;
//             } else if (mid_val < target) {
//                 i = mid + 1;
//             } else {
//                 return mid;
//             }
//         }
//         if (nums[i] == target)
//             return i;
        
//         return -1;
//     }
// };

//[-2,0,1,1,2]


int main()
{
    Solution s;
    vector<int> vec = {-1,0,1,2,-1,-4};
    auto res = s.threeSum(vec);
    for (auto r: res) {
        std::copy(r.begin(), r.end(), ostream_iterator<int>(cout, " "));
        cout << std::endl;
    }
}

