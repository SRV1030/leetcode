class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int low = 0, high = letters.size() - 1;
        while(low < high){
            int mid = (low + high) / 2;
            if(letters[mid] <= target)
                low = mid + 1;
            else high = mid;
        }
        if(low == letters.size() - 1 && letters[low] <= target)
            return letters[0];
        return letters[low];
    }
};