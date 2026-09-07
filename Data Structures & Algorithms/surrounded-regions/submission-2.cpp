class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int rows=board.size();
        int cols=board[0].size();
        queue<pair<int,int>> q;
        vector<vector<bool>> visited(rows,vector<bool>(cols,false));
        for(int i=0;i<rows;i++){
            if(board[i][0]=='O') {
                q.push({i,0});
                visited[i][0]=true;
            }
        }
        for(int i=0;i<rows;i++){
            if(board[i][cols-1]=='O') {
                q.push({i,cols-1});
                visited[i][cols-1]=true;
            }
        }
        for(int i=0;i<cols;i++){
            if(board[0][i]=='O') {
                q.push({0,i});
                visited[0][i]=true;
            }
        }
        for(int i=0;i<cols;i++){
            if(board[rows-1][i]=='O') {
                q.push({rows-1,i});
                visited[rows-1][i]=true;
            }
        }
        vector<pair<int,int>> dirs={{0,1},{1,0},{0,-1},{-1,0}};
        while(!q.empty()){
            pair<int,int> p=q.front();q.pop();
            for(auto [r,c]:dirs){
                int rc=r+p.first;
                int cc=c+p.second;
                if(rc<0||rc>=rows||cc<0||cc>=cols) continue;
                if(board[rc][cc]=='X' || visited[rc][cc]) continue;
                if(board[rc][cc]=='O') {visited[rc][cc]=true; q.push({rc,cc});}
            }
        }
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(board[i][j]=='O' && !visited[i][j]) board[i][j]='X';
            }
        }
    }
};
