class Solution {
public:
    vector<int> buildLPS(string &pat) {
        int m = pat.size();
        vector<int> lps(m);
        for(int ind = 1, len = 0; ind < m;){
            if(pat[ind] == pat[len]){
                lps[ind++] = ++len;
            }
            else if(len){
                len = lps[len - 1];
            }
            else
                ++ind;
        }
        return lps;
    }

    bool kmpSearch(string &text, string &pat) {
        vector<int> lps = buildLPS(pat);

        int i = 0, j = 0;
        int n = text.size();
        int m = pat.size();

        while (i < n) {
            if (text[i] == pat[j]) {
                i++;
                j++;

                if (j == m)
                    return true;
            } else {
                if (j)
                    j = lps[j - 1];
                else
                    i++;
            }
        }

        return false;
    }

    int repeatedStringMatch(string a, string b) {
        string s = a;

        int cnt = 1;

        while (s.size() < b.size()) {
            s += a;
            cnt++;
        }

        if (kmpSearch(s, b))
            return cnt;

        s += a;

        if (kmpSearch(s, b))
            return cnt + 1;

        return -1;
    }
};