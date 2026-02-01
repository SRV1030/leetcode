class WordDictionary {
    class Node{
        vector<Node*> children;
        bool isEnd;
    public:
        Node(){
            children = vector<Node*> (26);
            isEnd = false;
        }

        void setIsEnd(){
            isEnd= true;
        }

        bool getIsEnd(){
            return isEnd;
        }

        Node* putChar(char x){
            int chInd = x - 'a';
            if(!children[chInd])
                children[chInd] = new Node();
            return children[chInd];
        }

        Node* gotoChar(char x){
            return children[x - 'a'];
        }
        vector<Node*> getChildren(){
          return children;
        }
    };
    Node* root;
public:
    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        Node* node = root;
        for(auto& ch : word){
            node = node->putChar(ch);
        }
        node->setIsEnd();
    }
    
    bool search(string word, int ind, Node* node){
        if(!node)
            return false;
        if(ind == word.size())
            return node->getIsEnd();
        if(word[ind] == '.'){
            vector<Node*> children = node->getChildren();
            for(auto& child : children){
                if(child && search(word, ind + 1, child))
                    return true;
            }
            return false;
        }
        return search(word, ind + 1, node->gotoChar(word[ind]));
    }
    bool search(string word) {
        return search(word, 0, root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */