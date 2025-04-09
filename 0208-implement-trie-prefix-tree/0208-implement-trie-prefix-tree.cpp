class Node{
public:
    vector<Node*>children;
    bool isLast;
    Node(){
        children = vector<Node*>(26);
        isLast = false;
    }
    void putChar(char ch){
        if(!children[ch-'a']) children[ch-'a'] = new Node();
    }
    bool checkChar(char ch){
        return children[ch-'a']!=NULL;
    }
};
class Trie {
    Node *root;
public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node *currentNode = root;
        for(auto&ch:word){
            currentNode->putChar(ch);
            currentNode = currentNode->children[ch-'a'];
        }
        currentNode->isLast = true;
    }
    
    bool search(string word) {
        Node *currentNode = root;
        for(auto&ch:word){
            if(!currentNode->checkChar(ch)) return false;
            currentNode = currentNode->children[ch-'a'];
        }
        return currentNode->isLast;
    }
    
    bool startsWith(string prefix) {
        Node *currentNode = root;
        for(auto&ch:prefix){
            if(!currentNode->checkChar(ch)) return false;
            currentNode = currentNode->children[ch-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */