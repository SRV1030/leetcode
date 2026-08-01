class Solution {
    int size;
public:
    int evenFlip(string s){
        int diff1 = 0, diff2 = 0;
        for(int ind = 0; ind < size; ++ind){
            diff1 += (ind % 2) ? s[ind] == '1' : s[ind] == '0';
            diff2 += (ind % 2) ? s[ind] == '0' : s[ind] == '1';
        }
        return min(diff1, diff2);
    }
    int oddFlip(string s){
        int diff1 = 0, diff2 = 0;
        s += s;
        int total = 2 * size;
        int res = INT_MAX;
        for(int right = 0, left = 0; right < total; ++right){
            diff1 += (right % 2) ? s[right] == '1' : s[right] == '0';
            diff2 += (right % 2) ? s[right] == '0' : s[right] == '1';
            if(right - left + 1 > size){
                diff1 -= (left % 2) ? s[left] == '1' : s[left] == '0';
                diff2 -= (left % 2) ? s[left] == '0' : s[left] == '1';
                ++left;
            }
            if(right - left + 1 == size)
                res = min(res, min(diff1, diff2));
        }
        return res;
    }
    int minFlips(string s) {
        size = s.size();
        return size % 2? oddFlip(s) : evenFlip(s);
    }
};