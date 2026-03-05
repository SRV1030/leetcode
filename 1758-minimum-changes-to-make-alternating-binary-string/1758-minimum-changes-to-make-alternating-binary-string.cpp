class Solution {
public:
    int minOperations(string s) {
        int c1 = 0, c2 = 0;
        for(int index = 0; index < s.size(); ++index){
            if((index % 2 && s[index] == '0') || (index % 2 == 0 && s[index] == '1'))
                ++c1;
            if((index % 2 && s[index] == '1') || (index % 2 == 0 && s[index] == '0'))
                ++c2;
        }
        return min(c1, c2);
    }
};