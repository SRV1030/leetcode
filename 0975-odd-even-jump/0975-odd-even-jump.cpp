class Solution {
    int sizeOfArr;
public:
    int oddEvenJumps(vector<int>& arr) {
        sizeOfArr = arr.size();
        vector<int> oddJumps(sizeOfArr), evenJumps(sizeOfArr);
        map<int, int> numToIndex;
        oddJumps[sizeOfArr - 1] = evenJumps[sizeOfArr - 1] = 1;
        numToIndex[arr[sizeOfArr - 1]] = sizeOfArr - 1;
        int totalReachingEnd = 1;
        for(int index = sizeOfArr - 2; index >= 0; index--){
            auto evenJumpTo = numToIndex.upper_bound(arr[index]);
            auto oddJumpTo = numToIndex.lower_bound(arr[index]);
            if(oddJumpTo != numToIndex.end())
                oddJumps[index] = evenJumps[oddJumpTo->second];
            if(evenJumpTo != numToIndex.begin())
                evenJumps[index] = oddJumps[prev(evenJumpTo)->second];
            if(oddJumps[index])
                totalReachingEnd++;
            numToIndex[arr[index]] = index;
        }
        return totalReachingEnd;
    }
};

// https://leetcode.com/problems/odd-even-jump/solutions/1522948/c-solution-with-excessive-comments