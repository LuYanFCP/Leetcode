#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int gcd(int x, int y) {
        if (x < y) swap(x,y);
        if (y == 0) return x;
        else return gcd(y, x%y);
    }

    std::pair<int, int> slope(vector<int> &v1, vector<int> &v2) {
        /**
         * 核心问题1：
         * double做不了hash
        */
        int dx = v1[0] - v2[0];
        int dy = v1[1] - v2[1];
        if (dx == 0) return {0 , v1[0]};
        if (dy == 0) return {v1[0], 0};
        int x_y_gcd = gcd(abs(dx), abs(dy));
        return {dx/x_y_gcd, dy/x_y_gcd};
    }
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            map<pair<int, int>, int> counter;
            int same_points = 1, max_points = 0;
            for (int j = 0; j < n; ++j) {
                if (i == j) continue;
                // printf("%d %d\n", i, j);
                // 相等
                if (points[i][0] == points[j][0] && points[i][1] == points[j][1]) ++same_points;
                else max_points = std::max(max_points, ++counter[slope(points[i], points[j])]);
                // printf("%d, \n", max_points);
            }
            ans = max(ans, same_points+max_points);
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<vector<int>> points = {{1,1}, {2,2}, {3,3}};
    s.maxPoints(points);
    return 0;
}
