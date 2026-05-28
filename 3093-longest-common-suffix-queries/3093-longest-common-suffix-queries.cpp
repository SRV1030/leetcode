class Solution {

    class Node{
        int index;
        Node* children[26];

    public:
        Node(){
            index = -1;
            for(int i = 0; i < 26; i++) children[i] = nullptr;
        }

        ~Node(){
            for(int i = 0; i < 26; i++){
                if(children[i])
                    delete children[i];
            }
        }

        void setIndex(int _index){
            index = _index;
        }

        int getIndex(){
            return index;
        }

        Node* putNode(char x){
            int ind = x - 'a';
            if(!children[ind])
                children[ind] = new Node();
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

        ~Trie(){
            delete root;  // triggers recursive cleanup
        }

        void insert(vector<string>& wordsContainer){
            for(int index = 0; index < wordsContainer.size(); ++index){
                Node* cur = root;
                string& word = wordsContainer[index];
                int len = word.size();

                for(int ind = len - 1; ind >= 0; --ind){
                    cur = cur->putNode(word[ind]);

                    int prev = cur->getIndex();
                    if(prev == -1 || wordsContainer[prev].size() > len)
                        cur->setIndex(index);
                }

                int prev = root->getIndex();
                if(prev == -1 || wordsContainer[prev].size() > len)
                    root->setIndex(index);
            }
        }

        int getResult(const string& word){
            Node* cur = root;

            for(int ind = word.size() - 1; ind >= 0; --ind){
                Node* next = cur->gotoNode(word[ind]);
                if(next)
                    cur = next;
                else
                    break;
            }

            return cur->getIndex();
        }
    };

public:
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        Trie* trie = new Trie();

        trie->insert(wordsContainer);

        vector<int> res;
        for(auto& word : wordsQuery)
            res.push_back(trie->getResult(word));

        delete trie; 
        return res;
    }
};