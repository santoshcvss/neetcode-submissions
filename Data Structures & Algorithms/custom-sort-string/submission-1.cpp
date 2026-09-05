class Solution {
public:
    string customSortString(string order, string s) {
        unordered_set<char> s1;
        unordered_map<char,int> m2;

        string ans="";
        for(int i=0;i<s.size();i++){
            m2[s[i]]++;
        }
        for(int i=0;i<order.size();i++){
            s1.insert(order[i]);
            if(m2.find(order[i])!=m2.end()){
                while(m2[order[i]]){
                    ans+=order[i];
                    m2[order[i]]--;
                }
            }
        }
        for(auto it=m2.begin();it!=m2.end();it++){
            if(it->second !=0){
                while(m2[it->first]){
                    ans+=it->first;
                    m2[it->first]--;
                }
            }
        }
        return ans;
    }
};