#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> visited(n, 0);
        for (int i = 0; i < n; ++i) {
            if (visited[i] == 0  &&  !dfs(graph, visited, 1, i) ) {
                return false;
            }
        }
        return true;
    }
    bool dfs(vector<vector<int>>& graph, vector<int> &visited, int color, int node) {
        if (visited[node] != 0) {// 被访问过 {
            return visited[node] == color;
        }
        visited[node] = color;
        for (int node_i : graph[node])
            if (!dfs(graph, visited, -color, node_i)) return false;
        return true;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<vector<int>> vec = {{1,3},{0,2},{1,3},{0,2}};
    printf("%d\n", s.isBipartite(vec));
    return 0;
}
