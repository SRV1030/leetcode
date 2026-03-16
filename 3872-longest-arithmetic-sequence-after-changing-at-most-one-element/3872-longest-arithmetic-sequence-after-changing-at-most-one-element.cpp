class Solution {
public:
    int longestArithmetic(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int> l(n,1),r(n,1);

        for(int i = 1 ; i < n ; i++)
            if( i >= 2 && nums[i]-nums[i-1] == nums[i-1]-nums[i-2])
                l[i] = l[i-1]+1;
            else
                l[i]=2;
        for(int i = n-2 ; i >= 0 ; i--)
            if( i + 2 < n && nums[i+1]-nums[i] == nums[i+2]-nums[i+1])
                r[i] = r[i+1]+1;
            else
                r[i]=2;

        int ans = 2;
        for(int i = 0 ; i < n ; i++)
            ans = max(ans,l[i]+1);

        for(int i =1  ; i < n - 1 ; i++)
            {
                int t = nums[i-1] + nums[i+1];

                if(t%2 ==0)
                {
                    int d = (nums[i+1]-nums[i-1])/2;
                    int left = i>=2 && nums[i-1]-nums[i-2] == d ? l[i-1] : 1;
                    int right = i+2 < n && nums[i+2] - nums[i+1] == d ? r[i+1] : 1;
                    ans = max(ans,left + right + 1);
                    
                }
            }
        return min(ans,n);
    }
};