#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <climits>
using std::cout;
using std::vector;
using std::endl;
using std::min;
using std::max;

// #define min(a, b) (a) > (b) ? (b) : (a)
// #define max(a, b) (a) > (b) ? (a) : (b)


class Solution {
private:
    // int **ptr;
    // int len;
    int *ptr;
    
public:
    void Clear() {
        // for (int i = 0; i < len; i++) {
        //     delete[] ptr[i];
        // }
        // delete[] ptr;
        if (!ptr) {
            delete[] ptr;
        }
    }
    ~Solution() {
        Clear();
    }


    int maxArea(vector<int>& height) {
        /*
         *  从i-j之间最大的矩形为 m(i, j)
         *  它可以变成
         *  m(i, j) = max(m(i-1, j), m(i-1, j), min(h[i], h[j]) * (j - i))
         */
        int n = height.size();
        int rs = 0;

        // 初始化二维数组
        // len = n;
        // ptr = new int*[n];
        // for (int i = 0; i < n; i++) {
        //     ptr[i] = new int[n];
        // }
        ptr = new int[n]();

        // // 遍历数组进行计算   
        // for (int i = 1; i < n; i++) {
        //     for (int j = n - 1; j >=0; j--) {
        //         // if (j != 0) { 
        //         //     ptr[i][j] = max( max(ptr[i - 1][j], ptr[i][j - 1]), min(height[i], height[j]) * (i - j));
        //         // } else {
        //         //     ptr[i][j] = max(ptr[i - 1][j], (min(height[i], height[j]) * (i - j)));
        //         // }
        //         // cout << "{i: " << i << ", j:" << j << "}" << endl;
        //         cout << ptr[j] << endl;
        //         if (j != 0)
        //             ptr[j] = max(max (ptr[j], ptr[j - 1]), min(height[i], height[j]) * (i - j));
        //         else
        //             ptr[j] = max(ptr[j], min(height[i], height[j]) * (i - j));
        //         if (ptr[j] > rs)
        //             rs = ptr[j];
        //         // if (ptr[i][j] > rs) {
        //         //     rs = ptr[i][j];
        //         // }
        //     }
        // }      

	
		int p = 0,q = height.size() - 1;
		int ans=INT_MIN;
		while(p < q) {
			ans=max(ans, min(height[p],height[q]) * (q - p));
			if(height[p]<height[q]) p++;
			else q--;
        }
        return rs;

    }
};

int main() {
    Solution s;

    vector<int> heights{1, 8, 6, 2, 5, 4, 8, 3, 7}; 
    cout << s.maxArea(heights) << endl;

}