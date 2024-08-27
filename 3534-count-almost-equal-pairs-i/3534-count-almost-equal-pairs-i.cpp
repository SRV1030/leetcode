class Solution {
public:
    bool check(int i,int j){
        if(i>j)swap(i,j);
        string x=to_string(i),y=to_string(j);
        if(size(x)<size(y)){
            int d = size(y)-size(x)+1;
            while(--d) x = "0"+x;
        }
        int d=0;
        for(int i=0;i<size(y);++i){
            d+=x[i]!=y[i];
            if(d>2) return false;
        } 
        sort(begin(x),end(x));
        sort(begin(y),end(y));
        return x==y;
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