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
    Node* visited[101];
public:
    Node* cloneGraph(Node* node) {
        if(!node)
            return NULL;
        Node* clone = new Node(node->val);
        visited[node->val] = clone;
        for(auto& nb : node->neighbors){
            if(!visited[nb->val])
                cloneGraph(nb);
            clone->neighbors.push_back(visited[nb->val]);
        }
        return clone;
    }
};