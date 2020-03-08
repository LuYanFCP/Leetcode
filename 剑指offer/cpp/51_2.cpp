#include <vector>
#include <algorithm>
#include <unordered_map>
using std::vector;
using std::sort;
using std::unique;
using std::unordered_map;

class Solution {
public:
    int lowbit(int x) {
        return x & (-x);
    }

    void add(int i, vector<int>& c) {
        while(i <= c.size()) {
            c[i] += 1;
            i += lowbit(i);
        }
    }
    int ask(int i, vector<int>& c) {
        int res = 0;
        while(i) {
            res += c[i];
            i -= lowbit(i);
        }   
        return res;
    }
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        vector<int> vt;
        vector<int> c(n+20);
        for(auto i:nums) 
            vt.push_back(i);
        sort(vt.begin(),vt.end());
        vt.erase(unique(vt.begin(), vt.end()), vt.end()); // 得到一个不重复的有序序列
        unordered_map<int,int> mp;
        int cont=1;
        for(auto i:vt) mp[i]=cont++;  // 离散化标记
        int ans=0;
        for(int i = 0; i < nums.size(); ++i) {
            add(mp[nums[i]], c);
            ans += (i+1) - ask(mp[nums[i]], c);
        }
        return ans;
    }
};