class Solution {
public:

    string encode(vector<string>& strs) {
        string ans;
        if(strs.empty()){
            return ans;
        }
        for(int i=0;i<strs.size();i++){
            if(strs[i].empty()){
                ans+="emp";
            }
            ans+=strs[i]+"in"+to_string(i);
            cout<<ans<<endl;
        }
        return ans;
    }

    vector<string> decode(string s) {
        int index = 0;
        string until_i;
        vector<string> ans;
        if(s.empty()){
            return ans;
        }
        for(int i=0;i<s.size()-3;i++){
            until_i+=s[i];
            if(until_i=="emp"){
                until_i="";
            }
            if(s[i+1]=='i' && s[i+2]=='n'){
                int ind_s;
                cout<<until_i<<s[i+3]<<endl;
                try{
                    if( stoi(string(1,s[i+3]))==index ){
                        i+=3;
                    }
                    else if(stoi(s.substr(i+3,2))==index){
                        i+=4;
                    }
                    else if(stoi(s.substr(i+3,3))==index){
                        i+=5;
                    }
                    ans.push_back(until_i);
                    until_i="";
                    index++;
                }
                catch(...){
                    cout<<"moving on"<<endl;
                }
            }
        }
        return ans;
    }
};
