class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int freshOranges = 0;
        queue<pair<int, int>> q;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    freshOranges++;
                } else if (grid[i][j] == 2) {
                    q.push({i, j});
                }
            }
        }

        // No fresh oranges to rot initially (e.g., [[0]] or [[0, 2]])
        if (freshOranges == 0) {
            return 0;
        }

        int d[4][2] = {
            {0, -1}, // left
            {-1, 0}, // up
            {1, 0},  // down
            {0, 1}   // right
        };

        int minutes = 0;
        while (!q.empty()) {
            int size = q.size();
            bool rottedThisMinute = false;

            while (size--) {
                auto [x, y] = q.front();
                q.pop();

                for (int k = 0; k < 4; k++) {
                    int nx = x + d[k][0];
                    int ny = y + d[k][1];

                    if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == 1) {
                        grid[nx][ny] = 2;
                        freshOranges--;
                        rottedThisMinute = true;
                        q.push({nx, ny});
                    }
                }
            }

            if (rottedThisMinute) {
                minutes++;
            }
        }

        return freshOranges == 0 ? minutes : -1;
    }
};