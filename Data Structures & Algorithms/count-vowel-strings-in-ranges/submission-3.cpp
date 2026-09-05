class Solution {
public:
    bool isVovel(char c){
        if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u') return true;
        return false;
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> v;
        v.push_back(0);
        for(int i=1;i<=words.size();i++){
            int sze= words[i-1].size();
            int a=0;
            if(isVovel(words[i-1][0]) && isVovel(words[i-1][sze-1])) a=v[i-1]+1;
            else a=v[i-1];
            v.push_back(a);
        }

        vector<int> ans;
        for(int i=0;i<queries.size();i++){
            int an=0;
            an=v[queries[i][1]+1]-v[queries[i][0]];
            ans.push_back(an);
        }
        return ans;
    }
};