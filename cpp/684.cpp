#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> res{0, 0};
        init_uf(2*edges.size());
        for (vector<int>& edge:edges) {
            int first_root = find_uf(edge[0]);
            int second_root = find_uf(edge[1]);
            if (first_root == second_root) {
                res = edge; // copy assign
                continue;
            }
            parents[first_root] = second_root;
        }
        return res;
    }
    void init_uf(size_t n) {
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