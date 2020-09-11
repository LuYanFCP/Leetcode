#include <vector>
#include <iterator>
using namespace std;

class UnionFind
{

public:
    UnionFind(size_t size)
    {
        for (int i = 0; i < size; ++i)
            parents.push_back(i); // 父节点
        this->size = size;
        count = size;
    }
    int Find(int x)
    {
        int temp = x; // 记录下x
        while (x != parents[x])
        {
            parents[x] = parents[parents[x]];
            x = parents[x]; // 不停的去找当前节点的前一个节点
        }
        return x;
    }
    void Union(int x, int y)
    {
        int root_x = Find(x);
        int root_y = Find(y);
        if (root_x == root_y)
            return;
        parents[root_x] = root_y; // 把 y_root->
        --count;
    }

    size_t get_class_num()
    {
        return count;
    }
    // size_t get_class_num_if(int n) {
    //     vector<int> counter(size, 1);
    //     int count = 0;
    //     for (int i = 0; i < size; ++i) {
    //         int r = Find(i);
    //         if (r != i) {
    //             counter[r]++;
    //         }
    //     }
    //     for (int c: counter) {
    //         if (c >= n) {
    //             count++;
    //         }
    //     }
    //     return count;
    // }

private:
    vector<int> parents;
    size_t count;
    size_t size;
};

inline int get_index(int x, int y, int n, int m) { return x * m + y; }

class Solution
{
public:
    int numIslands(vector<vector<char>> &grid)
    {
        int n = grid.size();
        if (n == 0)
            return 0;
        int m = grid[0].size();
        size_t uf_size = n * m;
        int EMPTY = uf_size;       // 开个空节点，水池全部插入空节点
        UnionFind uf(uf_size + 1); // 让一个空节点
        vector<pair<int, int>> poss{{1, 0}, {0, 1}};
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (grid[i][j] == '0')
                {
                    uf.Union(get_index(i, j, n, m), EMPTY);
                    continue;
                }
                else
                {
                    for (pair<int, int> p : poss)
                    {
                        int new_x = i + p.first, new_y = j + p.second;
                        if (new_x < n && new_y < m && grid[new_x][new_y] == '1')
                        {
                            uf.Union(get_index(i, j, n, m), get_index(new_x, new_y, n, m));
                        }
                    }
                }
            }
        }
        return uf.get_class_num() - 1; // 这里直接将其计算树的个数
    }
};