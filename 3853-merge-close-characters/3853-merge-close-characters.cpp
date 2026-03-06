class Solution {
public:
    string mergeCharacters(string s, int k) {
        string res = "";
        vector<int> pos(26, -1);

        for(int index = 0; index < s.size(); ++index){
            int chInd = s[index] - 'a';

            if(pos[chInd] != -1 && res.size() - pos[chInd] <= k){
                continue;
            }

            res.push_back(s[index]);
            pos[chInd] = res.size() - 1;
        }

        return res;
    }
};