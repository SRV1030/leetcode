class Solution {
public:
    bool sumGame(string num) {
        int size = num.size(), half = size / 2;
        float resultant = 0.0;
        for(int index = 0; index < size; ++index){
            resultant += (index < half ? 1 : -1) * (num[index] == '?' ? 4.5 : num[index] - '0');
        }
        return resultant;
    }
};