class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& nums) {
        vector<long long> stack;
        for(auto& num : nums){
            long long temp = num;
            while(!stack.empty() && stack.back() == temp){
                temp += stack.back();
                stack.pop_back();
            }
            stack.push_back(temp);
        }
        return stack;
    }
};