class Solution {
public:
    bool isVovel(char c){
        if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u') return true;
        return false;
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        unordered_map<int, bool> m;
        for(int i=0;i<words.size();i++){
            int sze= words[i].size();
            if(isVovel(words[i][0]) && isVovel(words[i][sze-1])) m[i]=true;
            else m[i]=false;
        }

        vector<int> ans;
        for(int i=0;i<queries.size();i++){
            int an=0;
            for(int j=queries[i][0];j<=queries[i][1];j++){
                if(m[j]) an++;
            }
            ans.push_back(an);
        }
        return ans;
    }
};