#include <vector>
using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty())
            return 0;

        // m x n grid
        int m = grid.size();
        int n = grid[0].size();

        int islands{};    // number of islands
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '1') {
                    // set all points in this island to 'f' in grid
                    set(grid, m, n, i, j);
                    ++islands;    //increment number of islands
                }
            }
        }

        return islands;
    }

    void set(vector<vector<char>>& g, int m, int n, int x, int y) {
        // pass in m,n (dimensions of g) to avoid computing them again
        g[x][y] = 'f';

        // check for neighbours being 1s
        if (x != m - 1 && g[x + 1][y] == '1')
            set(g, m, n, x + 1, y);
        if (x != 0 && g[x - 1][y] == '1')
            set(g, m, n, x - 1, y);
        if (y != n - 1 && g[x][y + 1] == '1')
            set(g, m, n, x, y + 1);
        if (y != 0 && g[x][y - 1] == '1')
            set(g, m, n, x, y - 1);
    }
};