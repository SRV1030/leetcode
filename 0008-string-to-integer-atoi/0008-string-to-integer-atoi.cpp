class Solution {
public:
    int postSpaceIndex(string s){
        int index = 0;
        for(; index < s.size(); ++index)
            if(s[index] != ' ')
                break;
        return index;
    }
    int integer(string s,int sign,int index){
        long long num = 0;
        for(; index < s.size() && s[index] >= '0' && s[index] <='9'; ++index){
            num = num * 10 + (s[index] - '0');
            if(num > INT_MAX)
                return sign == -1 ? INT_MIN : INT_MAX;
        }
        return sign * num;
    }
    int myAtoi(string s) {
        int index = postSpaceIndex(s);
        if(index == s.size())
            return 0;
        int sign = 1;
        if(s[index] == '+' || s[index] == '-'){
            sign = s[index] == '-' ? -1 : 1;
            ++index;
        }
        return integer(s, sign, index);
    }
};