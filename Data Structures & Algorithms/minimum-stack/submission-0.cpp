class MinStack {
public:
    MinStack() {
    }
    stack<int> s;
    int mini=INT_MAX;
    vector<int> v;

    int nextMin(vector<int>& v){
        int m=INT_MAX;
        for(int i=0;i<v.size();i++){
            m=min(m,v[i]);
        }
        return m;
    }
    
    void push(int val) {
        mini=min(mini, val);
        s.push(val);
        v.push_back(val);
    }
    
    void pop() {
        s.pop();
        v.pop_back();
        mini=nextMin(v);
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return mini;
    }
};
