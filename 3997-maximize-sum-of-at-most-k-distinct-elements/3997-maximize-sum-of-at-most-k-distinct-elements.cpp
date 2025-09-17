class Solution {
public:
    vector<int> maxKDistinct(vector<int>& nums, int k) {
      vector<int> result;
      sort(nums.begin(), nums.end(), greater<int>());  
      for(auto& num : nums){
        if(result.empty())
            result.push_back(num);
        else if(num >= 0 && result.back() != num)
            result.push_back(num);
        if(result.size() == k)
            break;
      }
      return result;
    }
};