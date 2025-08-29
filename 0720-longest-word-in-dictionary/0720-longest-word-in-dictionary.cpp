class Solution {
public:
    class Node{
        string word;
        bool isEnd;
        vector<Node*> children;
    public:
        Node(){
            isEnd = false;
            word = "";
            children = vector<Node*> (26);
        }
        void setWord(string _word){
            word = _word;
        }
        string getWord(){
            return word;
        }
        void setIsEnd(){
            isEnd = true;
        }
        bool getIsEnd(){
            return isEnd;
        }
        Node* putChar(char x){
            int charIndex = x - 'a';
            if(!children[charIndex])
                children[charIndex] = new Node();
            return children[charIndex];
        }
        Node* gotoChar(char x){
            int charIndex = x - 'a';
            return children[charIndex];
        }
    };
    class Trie{
        Node* root;
    public:
        Trie(){
            root = new Node();
        }

        Node* getRoot(){
            return root;
        }

        void insert(string word){
            Node* node = root;
            for(auto& character :  word){
                node = node->putChar(character);
            }
            node->setIsEnd();
            node->setWord(word);
        }

        void getLargestWord(Node* node, string& largest){
            if (!node) return; 

            if (node != root && !node->getIsEnd())
                return;

            string nodeWord = node->getWord();
            if (nodeWord.size() > largest.size() || (nodeWord.size() == largest.size() && nodeWord < largest)) {
                largest = nodeWord;
            }

            for (char x = 'a'; x <= 'z'; ++x) {
                getLargestWord(node->gotoChar(x), largest);
            }
        }
    };
    string longestWord(vector<string>& words) {
        Trie trie;
        for(auto& word : words){
            trie.insert(word);
        }
        string largest = "";
        trie.getLargestWord(trie.getRoot(), largest);
        return largest;
    }
};