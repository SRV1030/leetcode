class Solution {
public:
    int numSteps(string s) {
        int carry = 0, steps = 0, sizeOfS = s.size();
        for(int index = sizeOfS - 1; index > 0; index--){
            ++steps;
            if(s[index] + carry - '0' == 1){
                carry = 1;
                ++steps;
            }
        }
        return steps + carry;
    }
};