class Solution {
public:
    int numSteps(string s) {
        int count = 0, carry = 0;
        for(int ind = s.size() - 1; ind > 0; --ind){
            int bit = s[ind] - '0';
            ++count;
            if(bit + carry == 1){
                ++count; 
                carry = 1;
            }
        }
        return count + carry;
    }
};