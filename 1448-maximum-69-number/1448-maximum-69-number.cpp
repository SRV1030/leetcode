class Solution {
public:
    int maximum69Number (int num) {
        string str = to_string(num);
        for(auto& charNum : str){
            if(charNum == '6'){
                charNum = '9';
                break;
            }
        }
        return stoi(str);
    }
};