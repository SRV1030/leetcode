class Solution {
public:
    int minimumLength(string st) {
        vector<int>f(26);
        for(auto&i:st)f[i-'a']++;
        int s = 0;
        for(auto&i:f)
            if(i) s+=(i%2)?1:2;
        return s;
    }
};