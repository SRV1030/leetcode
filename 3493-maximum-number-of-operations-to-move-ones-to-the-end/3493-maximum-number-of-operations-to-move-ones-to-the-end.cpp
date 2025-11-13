class Solution {
public:
    int maxOperations(string s) {
        int ops = 0;
        int oneCount = 0;
        for(int index = 0; index < s.size(); ++index){
            if(s[index] == '1')
                oneCount++;
            else if((index - 1) >= 0 && s[index - 1] == '1')
                ops += oneCount;
        }
        return ops;
    }
};