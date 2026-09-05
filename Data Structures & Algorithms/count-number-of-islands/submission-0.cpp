class Solution {
public:

    void dfs(int r, int c, int& rows, int& cols, vector<vector<char>>& grid, vector<pair<int,int>>& dirs, vector<vector<bool>>& visited){
        if(r<0 || r>=rows || c<0 || c>=cols) return;
        if(grid[r][c]=='0' || visited[r][c]) return;
        visited[r][c]=true;
        for(auto [dr, dc]:dirs){
            dfs(r+dr, c+dc, rows, cols, grid, dirs, visited);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int ans=0;
        int rows=grid.size();
        int cols=grid[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols,false));
        vector<pair<int,int>> dirs={{0,1}, {1,0}, {0,-1}, {-1,0}};
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]=='1' && !visited[i][j]){
                    dfs(i,j, rows, cols, grid, dirs, visited);
                    ans++;
                }
            }
        }
        return ans;
    }
};
