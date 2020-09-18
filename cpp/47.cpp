#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        unordered_set<string> hashset;
        vector<int> temp;
        vector<bool> visited(nums.size(), false);
        dfs(0, nums.size(), nums, temp, res, hashset, visited);
        return res;
    }
    void dfs(int idx, int n, vector<int>& nums , vector<int> &temp, vector<vector<int>>& res, unordered_set<string>& hashset, vector<bool>& visited) {
        if (temp.size() == n) {
            stringstream ss;
            copy(temp.begin(), temp.end(), ostream_iterator<int>(ss, ""));
            string str_arr = ss.str();
            if (hashset.find(str_arr) == hashset.end()) {
                res.emplace_back(temp);
                hashset.insert(str_arr);
            }
            return;
        }
        for (int i = 0; i<n; i++) {
            if (!visited[i]) {
                visited[i] = true;
                temp.push_back(nums[i]);
                dfs(i+1,n,nums, temp, res, hashset, visited);
                temp.pop_back();
                visited[i] = false;
            }
        }
    }
};