#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) return {};
        unordered_map<char, vector<char>> hash_map = {
            {'2', {'a', 'b', 'c'}}, 
            {'3', {'d', 'e', 'f'}},
            {'4', {'g', 'h', 'i'}},
            {'5', {'j', 'k', 'l'}},
            {'6', {'m', 'n', 'o'}},
            {'7', {'p', 'q', 'r', 's'}},
            {'8', {'t', 'u', 'v'}},
            {'9', {'w', 'x', 'y', 'z'}}
        };
        
        vector<string> res;
        vector<char> temp;
        dfs(digits, 0, hash_map, temp, res);
        return res;

    }
    void dfs(string &digits, int idx, unordered_map<char, vector<char>> &hash_map, vector<char> &temp,vector<string> &res)
    {
        int n = digits.size(), m = hash_map[digits[idx]].size();
        if (idx == n)  
            res.emplace_back(temp.begin(), temp.end());
        
        for (int i = 0; i < m; ++i) {
            temp.push_back(hash_map[digits[idx]][i]);
            dfs(digits, idx+1, hash_map, temp, res);
            temp.pop_back();
        }
    }
};