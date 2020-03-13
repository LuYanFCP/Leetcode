#include <vector>
using std::vector;

class NumArray {
public:
    NumArray(vector<int>& nums) {
        sum = new int[nums.size() + 1]; // 构建前缀和sum，只不过为了方便使用i位置不包含i的前缀和， 给sumRange少一个判断
        sum[0] = 0;
        for (int i = 1; i < nums.size() + 1; ++i) {
            sum[i] = sum[i-1] + nums[i-1];
        }
    }
    
    int sumRange(int i, int j) {
        return sum[j+1] - sum[i];
    }
    ~NumArray() {
        if (sum)
            delete[] sum;
    }
private:
    int* sum;
};
