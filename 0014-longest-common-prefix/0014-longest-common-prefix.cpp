class Solution {
public:
    class Node {
    public:
        Node* nxt[26];
        bool isEnd;
        int lc;
        Node() {
            isEnd = false;
            lc = 0;
            for (int i = 0; i < 26; ++i)
                nxt[i] = nullptr;
        }
        void put(char ch) {
            if (!nxt[ch - 'a']) {
                nxt[ch - 'a'] = new Node();
                ++lc;
            }
        }
    };

    class Trie {
    public:
        Node* root;
        Trie() { root = new Node(); }

        void insert(string word){
            Node *t=root;
            for(auto&c:word){
                if(!t->nxt[c-'a'])t->put(c);
                t=t->nxt[c-'a'];
            }
            t->isEnd = true;
        }

        string prefix(string word){
            Node *t=root;
            string pref="";
            for(auto&i:word){
                if(t->nxt[i-'a'] && t->lc==1 && !t->isEnd){
                    pref+=i;
                    t=t->nxt[i-'a'];
                }
                else break;
            }
            return pref;
        }
    };
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) return "";
        if(strs.size()==1) return strs[0];
        Trie tr;
        for(int i=1;i<strs.size();++i)tr.insert(strs[i]);
        return tr.prefix(strs[0]);
    }
};