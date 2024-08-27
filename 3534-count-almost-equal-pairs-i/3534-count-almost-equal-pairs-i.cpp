class Solution {
public:
    bool check(int i,int j){
        if(i>j)swap(i,j);
        string x=to_string(i),y=to_string(j);
        if(size(x)<size(y)){
            int d= size(y)-size(x)+1;
            while(--d) x.insert(0,"0");
        }
        int d=0;
        unordered_map<char,int> mp1, mp2;
        for(int i=0;i<size(y);++i){
            d+=x[i]!=y[i];
            if(d>2) return false;
            ++mp1[x[i]];
            ++mp2[y[i]];
        }
        return mp1==mp2;
    }
    int countPairs(vector<int>& nums) {
        int c=0;
        for(int i=0;i<size(nums);++i){
            for(int j=i+1;j<size(nums);++j){
                if(nums[i]==nums[j] || check(nums[i],nums[j]))++c;
            }
        }
        return c;
    }
};