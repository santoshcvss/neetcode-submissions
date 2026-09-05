class Solution {
public:
    bool isVovel(char c){
        if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u') return true;
        return false;
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        unordered_map<int, int> m;
        m[0]=0;
        for(int i=1;i<=words.size();i++){
            int sze= words[i-1].size();
            if(isVovel(words[i-1][0]) && isVovel(words[i-1][sze-1])) m[i]=m[i-1]+1;
            else m[i]=m[i-1];
        }

        vector<int> ans;
        for(int i=0;i<queries.size();i++){
            int an=0;
            an=m[queries[i][1]+1]-m[queries[i][0]];
            ans.push_back(an);
        }
        return ans;
    }
};