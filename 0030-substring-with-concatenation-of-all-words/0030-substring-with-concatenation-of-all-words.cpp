class Solution {
    class Node {
    public:
        vector<Node*> children;
        bool isEnd;
        int wordId;

        Node() {
            children.assign(26, nullptr);
            isEnd = false;
            wordId = -1;
        }

        Node* putChar(char ch) {
            int c = ch - 'a';

            if (!children[c])
                children[c] = new Node();

            return children[c];
        }

        Node* gotoChar(char ch) {
            return children[ch - 'a'];
        }
    };

    class Trie {
    public:
        Node* root;

        Trie() {
            root = new Node();
        }

        void insert(const string& word, int id) {
            Node* node = root;

            for (char ch : word)
                node = node->putChar(ch);

            node->isEnd = true;
            node->wordId = id;
        }

        int searchWord(const string& s, int start, int len) {
            Node* node = root;

            for (int i = start; i < start + len; i++) {
                node = node->gotoChar(s[i]);

                if (!node)
                    return -1;
            }

            return node->isEnd ? node->wordId : -1;
        }
    };

public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int n = s.size();
        int m = words.size();
        int wordLen = words[0].size();
        int totalLen = m * wordLen;

        vector<int> ans;

        if (n < totalLen)
            return ans;

        Trie trie;

        unordered_map<string, int> id;
        int nextId = 0;

        vector<int> required;

        // Assign one ID per distinct word
        for (auto& word : words) {
            if (!id.count(word)) {
                id[word] = nextId++;
                trie.insert(word, id[word]);
                required.push_back(0);
            }

            required[id[word]]++;
        }

        for (int start = 0; start + totalLen <= n; start++) {

            vector<int> seen(nextId, 0);
            int used = 0;

            for (int pos = start;
                 pos < start + totalLen;
                 pos += wordLen) {

                int wordId =
                    trie.searchWord(s, pos, wordLen);

                if (wordId == -1)
                    break;

                seen[wordId]++;

                if (seen[wordId] > required[wordId])
                    break;

                used++;
            }

            if (used == m)
                ans.push_back(start);
        }

        return ans;
    }
};