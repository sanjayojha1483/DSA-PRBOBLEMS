class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        if (heightMap.empty() || heightMap[0].empty()) return 0;
        
        int m = heightMap.size(), n = heightMap[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 || j == 0 || i == m - 1 || j == n - 1) {
                    pq.push({heightMap[i][j], i, j});
                    visited[i][j] = true;
                }
            }
        }
        
        int res = 0, dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
        
        while (!pq.empty()) {
            auto cur = pq.top(); pq.pop();
            int h = cur[0], x = cur[1], y = cur[2];
            
            for (int k = 0; k < 4; k++) {
                int nx = x + dirs[k][0], ny = y + dirs[k][1];
                if (nx < 0 || ny < 0 || nx >= m || ny >= n || visited[nx][ny]) continue;
                visited[nx][ny] = true;
                res += max(0, h - heightMap[nx][ny]);
                pq.push({max(h, heightMap[nx][ny]), nx, ny});
            }
        }
        
        return res;
    }
};
