#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        /* 进行统计 */
        int E = edges.size();
        vector<int> counter(2*E, 0);
        vector<vector<int>> idxs(2*E, vector<int>());  // 记录边的位置
        int target_node = -1;  // 找两个入度的node
        for (int i = 0; i < E; ++i) {
            auto edge = edges[i];
            counter[edge[1]]++;
            idxs[edge[1]].push_back(i);
            if (counter[edge[1]] == 2) {
                target_node = edge[1];
                break;
            }
        }
        // 判断, 是不是是环
        if (target_node == -1) {

            init_uf(2*E);
            for (int i = 0; i < E; ++i) {
                auto edge = edges[i];
                int first_root = find_uf(edge[0]);
                int second_root = find_uf(edge[1]);
                if (first_root == second_root) {
                    return edge;  // 找到了环路的最后一个
                }
                parents[first_root] = second_root;
            }
        }
        // printf("%d==%d,%d\n", target_node, idxs[target_node][0], idxs[target_node][1]);
        // 如果不是环
        vector<int> res;
        for (int idx: idxs[target_node]) {
            init_uf(2*E);
            int i = 0;
            for (i = 0; i < E; ++i) {
                if (i==idx) continue;
                auto edge = edges[i];
                int first_root = find_uf(edge[0]);
                int second_root = find_uf(edge[1]);
                if (first_root == second_root) {
                    // 不是树
                    break;
                }
                parents[first_root] = second_root;
            }
            if (i == E) {
                res = edges[idx];
            }
        }
        return res;

    }
    void init_uf(size_t n) {
        parents.clear();
        auto it = back_insert_iterator(parents);
        for (int i=0; i < n; ++i) it++ = i;
    }
    int find_uf(int x) {
        int i;
        for (i = x; i != parents[i]; i=parents[i]);
        return i;
    }

private:
    vector<int> parents;
};