#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        if (obstacleGrid[0][0]) return 0;
        for(int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (obstacleGrid[i][j]) {
                    obstacleGrid[i][j] = 0;
                } else {
                    if (i == 0 && j == 0) {
                        obstacleGrid[i][j] = 1;
                    } else if (i == 0) {
                        obstacleGrid[i][j] = obstacleGrid[i][j-1];
                    } else if (j == 0) {
                        obstacleGrid[i][j] = obstacleGrid[i-1][j];
                    } else {
                        obstacleGrid[i][j] = obstacleGrid[i][j-1] + obstacleGrid[i-1][j];
                    }
                }
            }
        }
        return obstacleGrid.back().back();
    }
};