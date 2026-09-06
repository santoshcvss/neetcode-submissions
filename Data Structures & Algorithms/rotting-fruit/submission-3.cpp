class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows=grid.size();
        int cols=grid[0].size();
        queue<pair<int,int>> q;
        bool aof=false;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]==1) aof=true;
                if(grid[i][j]==2) q.push({i,j});
            }
        }
        if(q.empty() && !aof) return 0;
        vector<pair<int,int>> dirs={{0,1},{1,0},{0,-1},{-1,0}};
        int ans=-1;
        while(!q.empty()){
            ans++;
            int s=q.size();
            for(int i=0;i<s;i++){
                pair<int,int> p=q.front();q.pop();
                for(auto[r,c]:dirs){
                    int rc=p.first+r;
                    int cc=p.second+c;
                    if(rc<0||rc>=rows||cc<0||cc>=cols) continue;
                    if(grid[rc][cc]!=1) continue;
                    grid[rc][cc]=2;
                    q.push({rc,cc});
                }
            }
        }
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]==1) return -1;
            }
        }
        return ans;
    }
};
