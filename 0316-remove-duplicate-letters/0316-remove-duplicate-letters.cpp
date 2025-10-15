class Solution {
public:
    string removeDuplicateLetters(string s) {
        bitset<26> vis;
        vector<int> lastSeen(26);
        string st;
        for(int index = 0; index < s.size(); ++index){
            lastSeen[s[index] - 'a'] = index;
        }
        for(int index = 0; index < s.size(); ++index){
            int charInd = s[index] - 'a';
            if(!vis[charInd]){
                while(!st.empty() && st.back() > s[index] && lastSeen[st.back() - 'a'] > index){
                    vis[st.back() - 'a'] = 0;
                    st.pop_back();
                }
                st.push_back(s[index]);
                vis[charInd] = 1;
            }   
        }
        return st;
    }
};