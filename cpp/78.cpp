class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;
        dfs(0, nums.size(), temp, nums, res);
        return res;
    }
    void dfs(int idx, int N, vector<int> &temp, vector<int> &nums, vector<vector<int>>& res) {
        res.emplace_back(temp);
        if (idx == N) {    
            return;
        }
        for (int i = idx; i < N; ++i) {
            temp.push_back(nums[i]);
            dfs(i+1, nums.size(), temp, nums, res);
            temp.pop_back();
        }
    }
};