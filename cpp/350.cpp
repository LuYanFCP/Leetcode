#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> hashmap;
        // unordered_set<int> set;
        vector<int> res;
        for (int num1: nums1) ++hashmap[num1];
        for (int num2: nums2)
            if (hashmap.find(num2) != hashmap.end()) 
                if (hashmap[num2]) {
                    res.push_back(num2);
                    --hashmap[num2];
                }
        return res;
    }
};
