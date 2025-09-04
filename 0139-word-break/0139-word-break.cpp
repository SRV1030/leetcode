class Solution {
    class Node{
        vector<Node*> children;
        bool isEnd;
    public:
        Node(){
            children = vector<Node*> (26);
            isEnd = false;
        }
        
        void setIsEnd(){
            isEnd = true;
        }

        bool getIsEnd(){
            return isEnd;
        }

        Node* putChar(char x){
            int charIndex= x - 'a';
            if(!children[charIndex])
                children[charIndex] = new Node();
            return children[charIndex];
        }

        Node* gotoChar(char x){
            return children[x - 'a'];
        }
    };
    class Trie{
        Node* root;
    public:
        Trie(){
            root = new Node();
        }

        void insert(string word){
            Node* node = root;
            for(auto& character : word){
                node = node->putChar(character);
            }
            node->setIsEnd();
        }

        bool search(string word){
            Node* node = root;
            for(auto& character : word){
                node = node->putChar(character);
                if(!node)
                    return false;
            }
            return node->getIsEnd();
        }
    };
    vector<int> memory;
    int size;
    Trie* trie;
public:
    bool segmentCheck(string s, int index){
        if(index >= size)
            return true;
        if(memory[index] != -1)
            return memory[index];
        for(int low = index; low < size; ++low){
            if(trie->search(s.substr(index, low - index + 1)) && segmentCheck(s, low + 1))
                return memory[index] = 1;
        }
        return memory[index] = 0;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        size = s.size();
        memory = vector<int> (size, -1);
        trie = new Trie();
        for(auto& word : wordDict){
            trie->insert(word);
        }
        return segmentCheck(s, 0);
    }
};