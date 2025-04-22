class Solution {
public:
    vector<vector<int>> allPermutations;
    int high;
    void generateAllPermutations(vector<int>& nums,int low){
        if(low==high)allPermutations.push_back(nums);
        else{
            for(int i=low;i<=high;i++){
                swap(nums[i],nums[low]);
                generateAllPermutations(nums,low+1);
                swap(nums[i],nums[low]);
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        high = nums.size()-1;
        generateAllPermutations(nums,0);
        return allPermutations;
    }
};