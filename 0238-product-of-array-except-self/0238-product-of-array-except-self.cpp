class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> result;
        long long product = 1;
        int zeroCount = 0;
        for(auto& num : nums){
            if(!num)
                ++zeroCount;
            else
                product *= num;
            if(zeroCount > 1)
                break;
        }
        for(auto& num : nums){
            if(zeroCount >= 1){
                if(num)
                    result.push_back(0);
                else
                    result.push_back((zeroCount == 1) ? product : 0);
            }
            else
                result.push_back(product / num);
        }
        return result;
    }
};