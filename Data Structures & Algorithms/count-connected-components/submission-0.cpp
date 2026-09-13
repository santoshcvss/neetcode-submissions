class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<bool> vis(n,false);
        unordered_map<int,vector<int>> adj;
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        queue<int>q;
        q.push(0);
        vis[0]=true;
        int ans=1;
        while(!q.empty()){
            int f=q.front(); q.pop();
            for(int i=0;i<adj[f].size();i++){
                if(!vis[adj[f][i]]){
                    q.push(adj[f][i]);
                    vis[adj[f][i]]=true;
                }
            }
            if(q.empty()){
                for(int i=0;i<vis.size();i++){
                    if(!vis[i]){
                        q.push(i);
                        vis[i]=true;
                        ans++;
                        break;
                    }
                }
            }
        }
        return ans;
    }
};
