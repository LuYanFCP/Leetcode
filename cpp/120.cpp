#include <vector>
#include <climits>

using std::vector;



class Solution {
public: 
    int minimumTotal(vector<vector<int>>& triangle) {
        int height = triangle.size();
        vector<int> vec = triangle[height-1];
        for (int i = height - 2; i >= 0; --i) {
            for (int j = 0; j <= i; ++j) {
                vec[j] = std::min(vec[j], vec[j+1]) + triangle[i][j];                
            }
        }
        return vec[0];
    }


    /*
     * 使用dfs 无法减枝，因此很慢
     */
    // void dfs(vector<vector<int>>& triangle, int i ,int j, int sum) {
    //     sum += triangle[i][j];
    //     // if (sum > min_sum)  // 
    //     //     return;

    //     if (i == height - 1) {
    //         if (sum < min_sum)
    //             min_sum = sum;
    //         return;
    //     }
        
    //     dfs(triangle, i + 1, i, sum);
    //     dfs(triangle, i + 1, i+1, sum);
    // }


};