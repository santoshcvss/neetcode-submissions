class Solution {
public:  

int find(int& x, vector<int>& par){
    int root = x;
    while(par[root]!=root){
        root=par[root];
    }
    return root;
}
                          
bool unionD(int& x, int& y,vector<int>& par){
    int rootX= find(x,par);
    int rootY = find(y,par);
    if(rootX == rootY){
        return false;
 }                                    par[rootX]=rootY;
    return true;
}
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<int> par(n+1, 0);
        for(int i=1; i<=n ; i++){
            par[i] = i;
        }
        for(int i=0; i<n; i++){
            int x= edges[i][0];
            int y = edges[i][1];
            if(!unionD(x,y,par)){
                return edges[i];
            }
        }
        vector<int> ans;
        return ans;
    }
};
