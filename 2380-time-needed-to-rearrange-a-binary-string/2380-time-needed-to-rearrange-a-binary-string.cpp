class Solution {
public:
    int secondsToRemoveOccurrences(string s) {
        int count = 0, z = 0;
        for(auto& bit : s){
            if(bit == '0')
                ++z;
            else if(z){
                count = max(count + 1, z);
            }
        }
        return count;
    }
};