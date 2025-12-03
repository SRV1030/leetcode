class Solution {
    vector<int> mirror = {0, 1, 5, -1, -1, 2, 9, -1, 8, 6};
    string numStr;
public:
    int countDP(int pos, bool isLast, bool mirrored){
        if(pos == numStr.size())
            return mirrored;
        int start = 0;
        int end = isLast ? numStr[pos] - '0' : 9;
        int count = 0;
        for(; start <= end; ++start){
            if(mirror[start] == -1)
                continue;
            count += countDP(pos + 1, isLast && (start == end), mirrored || (mirror[start] != start));
        }
        return count;
    }
    int rotatedDigits(int n) {
        numStr = to_string(n);
        return countDP(0, true, 0);
    }
};