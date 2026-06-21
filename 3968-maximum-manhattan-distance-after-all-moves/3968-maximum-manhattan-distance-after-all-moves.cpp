class Solution {
public:
    int maxDistance(string moves) {
        int x = 0, y = 0, us = 0;
        for(auto& move : moves){
            if(move == 'U')
                ++y;
            else if(move == 'D')
                --y;
            else if(move == 'L')
                --x;
            else if(move == 'R')
                ++x;
            else ++us;
        }
        return abs(x) + abs(y) + us;
    }
};