class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1)
           return s;
        map<int, string> zigzag;
        int key = 0, dir = 1;
        for(auto& character : s){
            key += dir;
            zigzag[key] += character;
            if(key == 1)
                dir = 1;
            else if(key == numRows)
                dir = -1;
        }
        string res = "";
        for(auto&[key, val] : zigzag)
            res += val;
        return res;
    }
};