class Solution {

public:
    class Node {
    public:
        vector<Node*> children;
        bool isEnd;
        int count;
        Node() {
            isEnd = false;
            count = 0;
            children.resize(26);
        }
    };

    class Trie {
    public:
        Node* root;
        int mp[100002] = {};
        set<int, greater<int>> st;
        Trie() { root = new Node(); }
        int getPrefix() { return !st.size() ? 0 : *st.begin(); }
        void insert(string s, int k) {
            Node* cur = root;
            for (int ind = 0; ind < s.size(); ind++) {
                char i = s[ind];
                if (!cur->children[i - 'a'])
                    cur->children[i - 'a'] = new Node();
                cur = cur->children[i - 'a'];
                cur->count++;
                if (cur->count >= k) {
                    mp[ind + 1]++;
                    if (mp[ind + 1] == 1)
                        st.insert(ind + 1);
                }
            }
            cur->isEnd = true;
        }
        void remove(string s, int k) {
            Node* cur = root;
            for (int ind = 0; ind < s.size(); ind++) {
                char i = s[ind];
                cur = cur->children[i - 'a'];
                cur->count--;
                if (cur->count == k - 1) {
                    mp[ind + 1]--;
                    if (!mp[ind + 1])
                        st.erase(ind + 1);
                }
            }
        }
    };
    vector<int> longestCommonPrefix(vector<string>& words, int k) {
        Trie* tr = new Trie();
        vector<int> res;
        for (auto& i : words)
            tr->insert(i, k);
        for (auto& i : words) {
            tr->remove(i, k);
            res.push_back(tr->getPrefix());
            tr->insert(i, k);
        }
        return res;
    }
};