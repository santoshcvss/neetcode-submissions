class Solution {
public:

    void dfs(int r, int c, int& rows, int& cols, vector<vector<int>>& grid, vector<vector<bool>>& visited, vector<pair<int,int>>& dirs, int& ans1){
        stack<pair<int,int>> st;
        visited[r][c]=true;
        st.push({r,c});
        while(!st.empty()){
            pair<int,int> p=st.top();
            ans1++;
            st.pop();
            for(auto [ri,ci]:dirs){
                if(p.first+ri<0||p.first+ri>=rows||p.second+ci<0||p.second+ci>=cols) continue;
                if(!visited[p.first+ri][p.second+ci] && grid[p.first+ri][p.second+ci]==1){
                    visited[p.first+ri][p.second+ci]=true;
                    st.push({p.first+ri,p.second+ci}); 
                } 
            }
        }
        return;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans=0;
        int rows=grid.size();
        int cols=grid[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        vector<pair<int,int>> dirs = {{0,1}, {1,0}, {0,-1}, {-1,0}};

        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]==1 && !visited[i][j]){
                    int ans1=0;
                    dfs(i,j,rows,cols,grid,visited,dirs,ans1);
                    ans=max(ans, ans1);
                }
            }
        }
        return ans;
    }
};
