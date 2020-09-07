#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> hashmap;
        for (int num : nums) {
            auto pos = hashmap.find(num);
            if (pos == hashmap.end()) hashmap[num] = 1;
            pos->second += 1;
        }
        // 排序
        vector<pair<int, int>> vec(hashmap.begin(), hashmap.end());
        sort(vec.begin(), vec.end(), [](const pair<int, int> &a, const pair<int, int> &b) {
            return b.second < a.second;
        });
        vector<int> res;
        for (int i = 0; i < k; ++k) {
            res.push_back(vec[i].first);
        }
        return res;
    }
};