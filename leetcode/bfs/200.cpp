class Solution {
public:
    void bfs(int start_i, int start_j, bool is_visited[][300], vector<vector<char>>& grid) {
        
        queue<pair<int, int>> q;
        int di[4] = {-1, 0, 1, 0}, dj[4] = {0, 1, 0, -1};
        int m = grid.size(), n = grid[0].size(), count = 0;
        
        q.push({ start_i, start_j });
        is_visited[start_i][start_j] = true;
        
        while (!q.empty()) {
            pair<int, int> current_loc = q.front();
            
            q.pop();
            
            for (int k = 0; k < 4; k++) {
                int new_i = current_loc.first + di[k], new_j = current_loc.second + dj[k];
                
                if (new_i >= 0 && new_i < m && new_j >= 0 && new_j < n && !is_visited[new_i][new_j] && grid[new_i][new_j] == '1') {
                    q.push({ new_i, new_j });
                    is_visited[new_i][new_j] = true;
                }
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        
        bool is_visited[300][300] = {false, };
        int m = grid.size(), n = grid[0].size(), count = 0;
        
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (!is_visited[i][j] && grid[i][j] == '1')
                    bfs(i, j, is_visited, grid), count++;
        
        return count;
    }
};
