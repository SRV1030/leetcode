class Solution {
    class Node{
        int id;
        bool isEnd;
        vector<Node*> children;
    public:
        Node(){
            id = -1;
            isEnd = false;
            children = vector<Node*>(26);
        }

        void setEnd(){
            isEnd = true;
        }

        bool getEnd(){
            return isEnd;
        }

        void setId(int id){
            this->id = id;
        }

        int getId(){
            return id;
        }

        Node* putNode(char x){
            int ind = x - 'a';
            if(!children[ind]){
                children[ind] = new Node();
            }
            return children[ind];
        }

        Node* gotoNode(char x){
            return children[x - 'a'];
        }
    };

    class Trie{
        Node* root;
    public:
        Trie(){
            root = new Node();
        }
        void insert(string word, int id){
            Node* node = root;
            for(auto& ch : word){
               node = node->putNode(ch);
            }
            node->setEnd();
            node->setId(id);
        }

        int search(string word){
            Node* node = root;
            for(auto& ch : word){
               node = node->gotoNode(ch);
               if(!node)
                return -1;
            }
            return node->getId();
        }
    };
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int id = 0, len = words[0].size();
        int sizeOfS = s.size(), sizeOfWords = words.size();
        int totalLen = len * sizeOfWords;
        vector<int> ans;

        if(sizeOfS < totalLen)
            return ans;

        unordered_map<string, int> wordId;
        vector<int> frequency;

        Trie* trie = new Trie();

        for(auto& word : words){
            if(!wordId.count(word)){
                wordId[word] = id;
                trie->insert(word, id++);
                frequency.push_back(0);
            }
            frequency[wordId[word]]++;
        }

        for(int start = 0; start + totalLen <= sizeOfS; ++start){
            vector<int> seen(id);
            int found = 0;
            for(int pos = start; pos + len <= start + totalLen; pos += len){
                int index = trie->search(s.substr(pos, len));
                if(index == -1)
                    break;
                seen[index]++;
                if(seen[index] > frequency[index])
                    break;
                ++found;
            }
            if(found == sizeOfWords)
                ans.push_back(start);
        }
        return ans;
    }
};