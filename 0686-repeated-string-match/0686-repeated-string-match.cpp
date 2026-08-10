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

        int tSz = text.size(), pSz = pat.size();
        for(int ti = 0, pi = 0; ti < tSz;){
            if(text[ti] == pat[pi]){
                ++ti;
                ++pi;
                if(pi == pSz)
                    return true;
            }
            else if(pi){
                pi = lps[pi - 1];
            }
            else
                ++ti;
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