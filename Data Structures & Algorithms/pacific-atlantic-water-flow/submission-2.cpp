class Solution {
public:
    bool bfs(int r, int c, int& rows, int& cols, vector<vector<int>>& grid){
        bool pasPos=false;
        bool atlPos=false;
        vector<pair<int,int>> dirs={{0,1},{-1,0},{0,-1},{1,0}};
        queue<pair<int,int>> q;
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        q.push({r,c});
        while(!q.empty()){
            int s=q.size();
            for(int i=0;i<s;i++){
                pair<int,int> p=q.front();q.pop();
                for(auto [ri,ci]:dirs){
                    int rc=p.first+ri;
                    int cc=p.second+ci;
                    if(rc>=rows || cc>=cols){
                        pasPos=true; continue;
                    }
                    if(rc<0|| cc<0){
                        atlPos=true; continue;
                    }
                    if(rc>=rows||rc<0||cc>=cols||cc<0) continue;
                    if(!visited[rc][cc] && grid[rc][cc]<=grid[p.first][p.second]){
                        q.push({rc,cc});
                        visited[rc][cc]=true;
                    }
                }
                if(pasPos && atlPos) return true;
            }
        }
        return false;
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int rows=heights.size();
        int cols=heights[0].size();
        vector<vector<int>> ans;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(bfs(i,j, rows, cols, heights)) ans.push_back({i,j});
            }
        }
        return ans;
    }
};
