class Solution {
public:
    int r, c;
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};

    class Node {
    public:
        char c;
        bool isTerminal;
        string word;
        unordered_map<char, Node*> nxt;
        Node(char a) {
            this->c = a;
            isTerminal = false;
            word = "";
        }
    };

    class Trie {
    public:
        Node* root;
        Trie() { root = new Node('\0'); }

        void insert(string c) {
            Node* t = root;
            for (auto& i : c) {
                if (!t->nxt.count(i))
                    t->nxt[i] = new Node(i);
                t = t->nxt[i];
            }
            t->isTerminal = true;
            t->word = c;
        }
    };

    void dfs(Node* root, vector<vector<char>> board, int i, int j,
             set<string>& ans) {
        if (min(i, j) < 0 || i >= r || j >= c || board[i][j] == '$')
            return;
        char c = board[i][j];
        if (!root->nxt.count(c))
            return;
        root = root->nxt[c];
        if (root->isTerminal) {
            ans.insert(root->word);
        }
        board[i][j] = '$';
        for (int d = 0; d < 4; d++)
            dfs(root, board, i + dx[d], j + dy[d], ans);
        board[i][j] = c;
    }
    vector<string> findWords(vector<vector<char>> board, vector<string> words) {
        Trie t;
        r = board.size();
        c = board[0].size();
        set<string> ans;
        for (auto& i : words)
            t.insert(i);
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
                dfs(t.root, board, i, j, ans);
        return vector<string>(ans.begin(),ans.end());
    }
};