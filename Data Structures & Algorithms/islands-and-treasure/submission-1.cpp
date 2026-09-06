class Solution {
public:
void bfs(vector<pair<int,int>>& dirs, int& rows, int& cols, vector<vector<int>>& grid, vector<vector<bool>>& visited, queue<pair<int,int>>& q ){
    int level=0;
    while(!q.empty()){
        level++;
        int s=q.size();
        for(int i=0;i<s;i++){
            pair<int,int> p=q.front();
            q.pop();
            for(auto [ri,ci]:dirs){
                int rc=ri+p.first;
                int cc=ci+p.second;
                if(rc<0 || rc>=rows||cc<0||cc>=cols) continue;
                if(visited[rc][cc] || grid[rc][cc]!=INT_MAX) continue;
                grid[rc][cc]= level;
                q.push({rc, cc});
                visited[rc][cc]=true;
            }
        }
    }
    return;
}
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int rows=grid.size();
        int cols=grid[0].size();
        vector<pair<int,int>> dirs={{0,1},{1,0},{0,-1},{-1,0}};
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]==0){
                    q.push({i,j});
                }
            }
        }
        bfs(dirs, rows, cols, grid, visited, q);
    }
};
