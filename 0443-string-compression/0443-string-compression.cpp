class Solution {
public:
    int compress(vector<char>& chars) {
        int count = 0;
        int prev = '\0';
        vector<char> result;
        for(auto& character : chars){
            if(character != prev){
                if(prev != '\0')
                    result.push_back(prev);
                if(count > 1){
                    string numStr =  to_string(count);
                    for(auto& num : numStr)
                        result.push_back(num);
                }
                count = 1;
                prev = character;
            }
            else
                ++count;
        }
        if(prev != '\0')
            result.push_back(prev);
        if(count > 1){
            string numStr =  to_string(count);
            for(auto& num : numStr)
                result.push_back(num);
        }
        chars = result;
        return result.size();
    }
};