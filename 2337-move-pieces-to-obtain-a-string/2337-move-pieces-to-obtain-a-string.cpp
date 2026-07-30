class Solution {
public:
    bool canChange(string start, string target) {
        int leftCount = 0, rightCount = 0;
        int size = start.size();

        for (int ind = 0; ind < size; ++ind) {

            // R in start
            if (start[ind] == 'R') {
                if (leftCount)
                    return false;
                ++rightCount;
            }

            // L in target
            if (target[ind] == 'L') {
                if (rightCount)
                    return false;
                ++leftCount;
            }

            // R in target
            if (target[ind] == 'R') {
                if (!rightCount)
                    return false;
                --rightCount;
            }

            // L in start
            if (start[ind] == 'L') {
                if (!leftCount)
                    return false;
                --leftCount;
            }
        }

        return leftCount == 0 && rightCount == 0;
    }
};