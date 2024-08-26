class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        auto c = [&] (auto& a, auto& b){
            return nums[a.first][a.second] > nums[b.first][b.second];
        };
        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(c)>pq(c);
        
        int mn = INT_MAX, mx=INT_MIN;

        for(int i=0; i<size(nums); ++i){
            mn=min(nums[i][0],mn);
            mx=max(nums[i][0],mx);
            pq.push({i,0});
        }
        vector<int> res({mn,mx});
        while(!pq.empty()){
            auto [i,j] = pq.top();
            pq.pop();
            if(++j == size(nums[i])) return res;
            pq.push({i,j});
            auto [x,y] = pq.top();
            mn = nums[x][y];
            mx = max(mx,nums[i][j]); 
            if(mx-mn<res[1]-res[0]) res = {mn,mx};
        }
        return res;
    }
};