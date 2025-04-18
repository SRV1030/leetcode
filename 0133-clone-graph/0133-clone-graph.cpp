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
    Node* vis[101];
public:
    Node* cloneGraph(Node* node) {
        if(!node) return node;
        Node* copy = new Node(node->val);
        vis[node->val]=copy;
        for(auto&nb:node->neighbors){
            if(!vis[nb->val]){
                Node* nbCopy = cloneGraph(nb);
                copy->neighbors.push_back(nbCopy);
            }
            else copy->neighbors.push_back(vis[nb->val]);
        }
        return copy;
    }
};