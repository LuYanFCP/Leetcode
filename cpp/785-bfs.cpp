#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        size_t n = graph.size();
        vector<int> visited(n, 0);
        for (int i = 0; i < n; ++i) {
            if (visited[i] == 0 && !bfs(graph, visited, i)) return false;
        }
        return true;
    }
    bool bfs(vector<vector<int>>& graph, vector<int> &visited, int begin_node) {
        queue<int> q;
        q.push(begin_node);
        visited[begin_node] = 1;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            int color = visited[node];
            for (int node_i: graph[node]) {
                if (visited[node_i] != 0) {
                    if (visited[node_i] != -color) return false;
                } else {
                    visited[node_i] = -color;
                    q.push(node_i);
                }
            }
        }
        return true;
    }
};