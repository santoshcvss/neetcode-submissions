class Solution {
public:
void bfs(vector<pair<int,int>>& dirs, int& rows, int& cols, vector<vector<int>>& grid, queue<pair<int,int>>& q ){
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
                if(grid[rc][cc]!=INT_MAX) continue;
                grid[rc][cc]= level;
                q.push({rc, cc});
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
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]==0){
                    q.push({i,j});
                }
            }
        }
        bfs(dirs, rows, cols, grid, q);
    }
};
