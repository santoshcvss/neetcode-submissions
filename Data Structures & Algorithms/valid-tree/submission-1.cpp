class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size()!=n-1) return false;
        unordered_map<int, vector<int>> m;
        vector<int> vis(n,0);
        for(int i=0;i<edges.size();i++){
            m[edges[i][1]].push_back(edges[i][0]);
            m[edges[i][0]].push_back(edges[i][1]);
        }
        queue<int> q;
        q.push(0);
        int count=0;
        while(!q.empty()){
            int f=q.front(); q.pop();
            vis[f]=1; count++;
            for(int i=0;i<m[f].size();i++){
                if(vis[m[f][i]]!=1) q.push(m[f][i]);
            }
        }
        if(count==n) return true;
        return false;
    }
};
