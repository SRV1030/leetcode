class Solution {
public:
    long long findScore(vector<int>& nums) {
        long long score = 0;
        vector<pair<int,int>> pr;
        for(int i=0;i<size(nums);++i)pr.push_back({nums[i],i});
        sort(pr.begin(),pr.end());
        for(int i=0;i<size(nums);++i){
            int x = pr[i].first, y= pr[i].second;
            if(nums[y]>=0){
                score+=x;
                nums[y]=-1;
                if(y-1>=0)nums[y-1]=-1;
                if(y+1<nums.size())nums[y+1]=-1;
            }
        }
        return score;
    }
};