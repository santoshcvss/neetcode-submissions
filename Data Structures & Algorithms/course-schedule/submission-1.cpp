class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prereq) {
        unordered_map<int,vector<int>> m;
        vector<int> in(numCourses,0);
        for(int i=0;i<prereq.size();i++){
            m[prereq[i][1]].push_back(prereq[i][0]);
            in[prereq[i][0]]++;
        }
        int count=0;
        queue<int> q;
        for(int i=0;i<in.size();i++){
            if(in[i]==0){
                q.push(i); 
            }
        }
        while(!q.empty()){
            count++;
            int f=q.front();q.pop();
            for(int i=0;i<m[f].size();i++){
                in[m[f][i]]--;
                if(in[m[f][i]]==0) q.push(m[f][i]);
            }
        }
        if(count==numCourses) return true;
        return false;
    }
};
