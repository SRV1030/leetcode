class Solution {
    int sumOfDg(int num){
        int x = num, sum = 0;
        while(x){
            sum += x % 10;
            x /= 10;
        }
        return sum;
    }
public:
    int smallestIndex(vector<int>& nums) {
        for(int ind = 0; ind < nums.size(); ++ind){
            if(ind == sumOfDg(nums[ind])){
                return ind;
            }
        }
        return -1;
    }
};