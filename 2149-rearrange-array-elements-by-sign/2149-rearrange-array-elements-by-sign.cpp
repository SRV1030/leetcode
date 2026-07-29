class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int pos = 0, neg = 1;
        int size = nums.size();
        vector<int> temp(size);
        for(auto& num : nums){
            if(num < 0){
                temp[neg] = num;
                neg += 2; 
            }
            else{
                temp[pos] = num;
                pos += 2;
            }
        }
        return temp;
    }
};