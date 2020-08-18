#include <bits/stdc++.h>

using namespace std;

class Solution {

    public:
    int maxDistance(vector<int>& position, int m) {
        int n = position.size();
        sort(position.begin(), position.end());  // 排序
        vector<int> dist(n-1, 0);
        for (int i = 0; i < n-1; ++i) dist[i] = position[i+1] - position[i];
        // copy(dist.begin(), dist.end(), ostream_iterator<int>(cout, " "));
        // printf("\n");

        int l = 0, r = 1e9, mid, ans;
        while (l <= r)
        {
            mid = l + (r-l)/2;
            bool flag = check(dist, mid, m-1);
            // printf("l:%d, r:%d, mid:%d, flag:%d\n", l, r, mid, flag);
            if (!flag) r = mid - 1;
            else {
                ans = mid;
                l = mid + 1;
            }
        }
        return ans;      
    }
    bool check(vector<int> &dist, int mid, int m) {
        int num = 0, total_dist = 0;
        int length = dist.size();
        for (int i = 0; i < length; ++i) {
            total_dist += dist[i];
            if (total_dist >= mid) {
                num++;
                total_dist = 0;
                if (num >= m) return true; // 放满了
    
            }
        }
        return num >= m; // 如果大则缩小
    }
};