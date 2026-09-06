class Solution {
public:
    void bfs(queue<pair<int,int>>& q, int& rows, int& cols, vector<vector<int>>& grid, vector<vector<bool>>& visited ){
        vector<pair<int,int>> dirs={{0,1},{-1,0},{0,-1},{1,0}};
        while(!q.empty()){
            int s=q.size();
            for(int i=0;i<s;i++){
                pair<int,int> p=q.front();q.pop();
                for(auto [ri,ci]:dirs){
                    int rc=p.first+ri;
                    int cc=p.second+ci;
                    if(rc>=rows||rc<0||cc>=cols||cc<0) continue;
                    if(!visited[rc][cc] && grid[rc][cc]>=grid[p.first][p.second]){
                        visited[rc][cc]=true;
                        q.push({rc,cc});
                    }
                }
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int rows=heights.size();
        int cols=heights[0].size();
        vector<vector<int>> ans;
        vector<vector<bool>> pas(rows, vector<bool>(cols,false));
        vector<vector<bool>> atl(rows, vector<bool>(cols,false));
        queue<pair<int,int>> qPas;
        queue<pair<int,int>> qAtl;
        for(int i=0;i<cols;i++){
            qPas.push({0,i});
            pas[0][i]=true;
        }
        for(int j=0;j<rows;j++){
            qPas.push({j,0});
            pas[j][0]=true;
        }
        for(int i=0;i<cols;i++){
            qAtl.push({rows-1,i});
            atl[rows-1][i]=true;
        }
        for(int j=0;j<rows;j++){
            qAtl.push({j,cols-1});
            atl[j][cols-1]=true;
        }
        bfs(qPas, rows, cols, heights, pas);
        bfs(qAtl, rows, cols, heights, atl);

        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(pas[i][j] && atl[i][j]) ans.push_back({i,j});
            }
        }
        return ans;
    }
};
