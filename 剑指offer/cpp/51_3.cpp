#include <vector>
#include <algorithm>
#include <unordered_map>
#include <iterator>

using std::vector;
using std::sort;
using std::unique;
using std::unordered_map;

class Solution {
public:
    int lowbit(int x) {
        return x & (-x);
    }
    void add(int x, vector<int>& t) {
        int n = t.size() - 1;
        for (; x <= n; x += x & (-x)) t[x] += 1;  
    }
    int ask(int x, vector<int>& t) {
        int res = 0;
        for (; x > 0; x -= x & (-x)) res += t[x];
        return res;
    }
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        vector<int> vec_elem;
        std::copy(nums.begin(), nums.end(), std::back_insert_iterator(vec_elem));
        sort(vec_elem.begin(), vec_elem.end());  // 删除重复的
        vec_elem.erase(unique(vec_elem.begin(), vec_elem.end()), vec_elem.end());  // 离散化操作
        int count = 1;  // 标记计数
        unordered_map<int, int> hashmap;
        for (int elem : vec_elem) {
            hashmap[elem] = count++;
        }
        vector<int> t(n + 1);
        int ans = 0;
        for (int i = 0; i < nums.size(); ++i) {
            add(hashmap[nums[i]], t);
            ans += (i+1) - ask(hashmap[nums[i]], t);
        }
        return ans;
    }
};