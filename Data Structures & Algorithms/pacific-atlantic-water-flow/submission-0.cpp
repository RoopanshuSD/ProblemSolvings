class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        vector<vector<int>> visited(n, vector<int>(m, 0));
        queue<tuple<int, int, int>> q;
        vector<vector<int>> ans;

        // Helper for initial border seeding: adds ocean (1 or 2) without double-pushing
        auto seed = [&](int r, int c, int ocean) {
            int prev = visited[r][c];
            // Only add this ocean if not already accounted for, and avoid re-seeding >= 3
            if (prev == ocean || prev >= 3) return;

            int cur = prev + ocean;
            visited[r][c] = cur;
            if (prev < 3 && cur >= 3) {
                ans.push_back({r, c});
            }
            q.emplace(r, c, cur);
        };

        for (int i = 0; i < n; i++) {
            seed(i, 0, 1);     // Left -> Pacific
            seed(i, m - 1, 2); // Right -> Atlantic
        }
        for (int j = 0; j < m; j++) {
            seed(0, j, 1);     // Top -> Pacific
            seed(n - 1, j, 2); // Bottom -> Atlantic
        }

        while (!q.empty()) {
            auto [x, y, o] = q.front();
            q.pop();

            // Always read the latest state of (x, y) in case it got upgraded while in queue
            int cur_o = visited[x][y];

            for (int d = 0; d < 4; d++) {
                int nx = x + dir[d][0];
                int ny = y + dir[d][1];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if (heights[nx][ny] < heights[x][y]) continue;

                int n_vis = visited[nx][ny];

                // Case 1: Current cell reaches both (>= 3), and neighbor hasn't reached both yet
                if (cur_o >= 3 && n_vis < 3) {
                    int next_val = n_vis + 3; // >= 3
                    visited[nx][ny] = next_val;
                    ans.push_back({nx, ny}); // n_vis was < 3 and next_val >= 3
                    q.emplace(nx, ny, next_val);
                }
                // Case 2: Current cell has single ocean (1 or 2), neighbor doesn't have it and < 3
                else if (cur_o < 3 && n_vis < 3 && n_vis != cur_o) {
                    int next_val = n_vis + cur_o;
                    visited[nx][ny] = next_val;
                    if (next_val >= 3) {
                        ans.push_back({nx, ny});
                    }
                    q.emplace(nx, ny, next_val);
                }
            }
        }

        return ans;
    }
};