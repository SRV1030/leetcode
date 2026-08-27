class Solution {
    vector<int> fr;
    string res;
public:
    bool isPos(int ind, string& temp, string& target, bool greater){
        if(ind == target.size()){
            if(greater){
                res = temp;
                return true;
            }
            return false;
        }
        int targetChInd = target[ind] - 'a';
        int cur = greater ? 0 : targetChInd;
        for(; cur < 26; ++cur){
            if(fr[cur]){
                fr[cur]--;
                temp.push_back('a' + cur);
                if(isPos(ind + 1, temp, target, greater | (cur > targetChInd)))
                    return true;
                fr[cur]++;
                temp.pop_back();
            }
        }
        return false;
    }
    string lexGreaterPermutation(string s, string target) {
        fr.resize(26);
        for(auto& ch : s)
            fr[ch - 'a']++;
        string temp;
        if(isPos(0, temp, target, false))
            return res;
        return "";
    }
};