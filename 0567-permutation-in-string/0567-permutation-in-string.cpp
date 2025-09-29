class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> f1(26), f2(26);
        for(auto& s : s1)
            f1[s - 'a']++;
        for(int left = 0, right = 0; right < s2.size(); ++right){
            f2[s2[right] - 'a']++;
            if((right - left + 1) > s1.size()){
                f2[s2[left++] - 'a']--;
            }
            if(f1 == f2)
                return true;
        }
        return false;
    }
};