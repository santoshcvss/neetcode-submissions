class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prereq) {
        unordered_map<int, vector<int>> m;
        vector<int> in(numCourses, 0);
        for(int i=0;i<prereq.size();i++){
            vector<int> vi=prereq[i];
            m[vi[1]].push_back(vi[0]);
            in[vi[0]]++;
        }
        queue<int> q;
        for(int i=0;i<in.size();i++){
            if(in[i]==0) q.push(i);
        }
        vector<int> ans;
        while(!q.empty()){
            int f=q.front(); q.pop();
            ans.push_back(f);
            for(int i=0;i<m[f].size();i++){
                in[m[f][i]]--;
                if(in[m[f][i]]==0) q.push(m[f][i]);
            }
        }
        if(numCourses==ans.size()) return ans;
        vector<int> ans1;
        return ans1;
    }
};
