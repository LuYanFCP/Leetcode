#include <bits/stdc++.h>

using namespace std;

struct pos{
    int x;
    int y;
    pos(int _x, int _y): x(_x), y(_y){};
    pos operator+(const pos &a) {
        return pos(a.x+this->x, a.y+this->y);
    }
    void print() {
        printf("%d, %d\n", this->x, this->y);
    }
};

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        queue<pos> q;
        pos postions[] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        int color = image[sr][sc];
        int m = image.size(), n = image[0].size();
        vector<vector<bool>> visited(m, vector(n, false));
        // printf("(%d, %d)==color:%d\n", m, n, color);
        q.push(pos(sr, sc));
        visited[sr][sc] = true;
        while (!q.empty())
        {
            pos p = q.front();
            // p.print();
            image[p.x][p.y] = newColor;
            visited[p.x][p.y] = true;

            q.pop();
            for (pos _add: postions) {
                pos new_pos = p + _add;
                // new_pos.print();
                if (check(new_pos, image, visited, m, n, color)) q.push(new_pos);
            }

        }
        return image;
    }

    static 
    inline bool check(const pos &_pos, const vector<vector<int>>& image, vector<vector<bool>> &visited, int m, int n, int color) {
        return _pos.x >= 0 && _pos.x < m && _pos.y >= 0 && _pos.y < n && image[_pos.x][_pos.y] == color && visited[_pos.x][_pos.y] == false;
    }
};