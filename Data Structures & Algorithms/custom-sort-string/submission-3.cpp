class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char,int> m2;

        string ans="";
        for(int i=0;i<s.size();i++){
            m2[s[i]]++;
        }
        for(int i=0;i<order.size();i++){
            // while(m2[order[i]]){
            //     ans+=order[i];
            //     m2[order[i]]--;
            // }
            if(m2.count(order[i])) {
                ans+=string(m2[order[i]], order[i]);
                m2[order[i]]=0;
            }
        }
        for(auto it=m2.begin();it!=m2.end();it++){
            if(it->second !=0){
                // while(m2[it->first]){
                //     ans+=it->first;
                //     m2[it->first]--;
                // }
                if(m2.count(it->first)){
                    ans+=string(m2[it->first], it->first);
                    m2[it->first]=0;
                }
            }
        }
        return ans;
    }
};