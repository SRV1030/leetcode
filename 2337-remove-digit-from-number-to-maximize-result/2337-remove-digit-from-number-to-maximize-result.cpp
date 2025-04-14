class Solution {
public:
    string removeDigit(string number, char digit) {
        int ind = -1, size = number.size();
        for (int i = 0; i < size; ++i) {
            if (number[i] == digit) {
                if (i + 1 < size && number[i] < number[i + 1]) {
                    ind = i;
                    break;
                } else
                    ind = i;
            }
        }
        number.erase(number.begin() + ind);
        return number;
    }
};