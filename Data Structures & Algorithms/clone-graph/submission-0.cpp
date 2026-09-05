/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node) return node;
        unordered_set<Node*> visited;
        unordered_map<Node*, Node*> oldnew;
        stack<Node*> s;
        s.push(node);
        bool firstNode=true;
        Node* ans;
        while(!s.empty()){
            Node* curNode=s.top();
            visited.insert(curNode);
            Node* newNode= new Node();
            newNode->val=curNode->val;
            oldnew[curNode]=newNode;
            //vector<Node*> l;
            s.pop();
            for(auto i:curNode->neighbors){
                if(visited.count(i)==0){
                    s.push(i);
                    //l.push_back(i);
                }
            }
            //newNode->neighbors=l;
            if(firstNode){
                ans=newNode;
                firstNode=false;
            }
        }
        for(auto& [oldN, newN]:oldnew){
            vector<Node*> v = oldN->neighbors;
            vector<Node*> vNew;
            for(auto i:v){
                vNew.push_back(oldnew[i]);
            }
            newN->neighbors=vNew;
        }
        return ans;
    }
};
