#include <vector>
#include <iterator>
#include <iostream>
#include <algorithm>
using std::vector;

class NumArray {
public:
    NumArray(vector<int>& nums) {
        // 建立树
        int n = nums.size();
        this->n = n;
        t = new int[n+1];
        _nums = new int[n];
        std::fill(t, t+n+1, 0);
        std::copy(nums.begin(), nums.end(), _nums);
        for (int i = 0; i < n; i++) {
            int num = nums[i];
            for (int x = i+1; x<=n; x += bitlow(x))  t[x] += num;
        }
        // std::copy(t+1, t+n+1, std::ostream_iterator<int>(std::cout, " "));
    }
    
    void update(int i, int val) {
        int diff = val - _nums[i];
        _nums[i] = val;
        for (int x = i+1; x<=n; x += bitlow(x)) t[x] += diff;

    }
    
    int sumRange(int i, int j) {
        int ans_i = 0, ans_j = 0;
        for (int t_i = i; t_i; t_i -= bitlow(t_i)) ans_i += t[t_i]; // ask(i-1)
        for (int t_j = j + 1; t_j; t_j -= bitlow(t_j)) ans_j += t[t_j]; // ask(j) 
        return ans_j - ans_i;

    }
    
    int bitlow(int x) {
        return x & (-x);
    }
    ~NumArray() {
        if (t)
            delete[] t;
    }

private:
int* _nums;
int* t;
int n;

};
