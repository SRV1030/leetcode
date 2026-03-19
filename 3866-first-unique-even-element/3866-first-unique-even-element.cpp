class Solution {
public:
    int firstUniqueEven(vector<int>& nums) {
        vector<int> fr(51);
        for(auto& num : nums){
            if(num % 2)
                continue;
            fr[num / 2] ++;
        }
        for(auto& num : nums){
            if(num % 2 == 0 && fr[num / 2] == 1)
                return num;
        }
        return -1;
    }
};