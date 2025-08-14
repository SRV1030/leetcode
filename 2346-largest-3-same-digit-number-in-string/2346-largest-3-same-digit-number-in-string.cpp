class Solution {
public:
    string largestGoodInteger(string num) {
        string result= "";
        for(int index = 0; index <= num.size() - 3; ++index){
            string str = num.substr(index, 3);
            if(str[0] == str[1] && str[1] == str[2]){
                result = max(result, str);
            }
        }
        return result;

    }
};