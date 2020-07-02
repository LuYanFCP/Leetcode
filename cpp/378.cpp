#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val, x, y;
    Node(int _val, int _x, int _y): val(_val), x(_x), y(_y) {};
    bool operator < (const Node &x) const {
        return val >= x.val;
    }
};


class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int min = INT_MAX, pos;
        unordered_map<int, int> poss;
        for (int i = 0; i < n; ++i) poss[i] = 0;
        for (int i = 0; i < k; ++i) {
            min = INT_MAX;
            for (int j = 0; j < n; j++) {
                if (poss[j] == n) continue;
                if (matrix[j][poss[j]] < min) {
                    min = matrix[j][poss[j]];
                    pos = j;
                }
            }
            poss[pos]++; // 更新1索引
        }        return min;
    }

    int kthSmallest2(vector<vector<int>>& matrix, int k) {
        int n = matrix.size(), res;
        priority_queue<Node> heapq;
        for (int i = 0; i < n; ++i) heapq.emplace(matrix[i][0], i, 0);
        for (int i = 0; i < k; ++i) {
            Node temp_node = heapq.top();
            res = temp_node.val;
            heapq.pop(); // 弹出
            if (temp_node.y < n-1) heapq.emplace(matrix[temp_node.x][temp_node.y+1], temp_node.x, temp_node.y+1);
        }
        return res;
    }

    int kthSmallest3(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int left = matrix[0][0], right = matrix[n-1][n-1];
        int mid, i, j, count;
        while (left < right) {
            mid = (right - left) / 2 + left;
            i = n - 1;
            j = 0;
            count = 0;
            while (i >= 0 && j < n) {
                if (matrix[i][j] <= mid) {
                    count += i+1;
                    ++j;
                } else {
                    --i;
                }
            }
            if (count < k) left = mid + 1;
            else right = mid;
        }
        return left;
    }
};