class Solution {
public:
    const int N = 1001;
    void fillS(vector<int>&pr){
        vector<int>isPr(1001);
        for(int i=3;i<1001;i+=2) isPr[i]=1;
        isPr[2]=1;
        for(int i=3;i<1001;i++){
            if(isPr[i]) for(int j=i*i;j<1001;j+=i)isPr[j]=0;
        }
        int lp = 2;
        for(int i=2;i<1001;++i){
            if(isPr[i]){
                pr[i]=i;
                lp=i;
            }
            else pr[i]=lp;
        }
    }
    bool primeSubOperation(vector<int>& nums) {
        vector<int>pr(N);
        fillS(pr);
        for(int i=0;i<size(nums);++i){
            if(i==0) nums[i]-=pr[nums[i]-1];
            else{
                int dif = nums[i] - nums[i-1];
                if( dif<=0 ) return false;
                nums[i]-=pr[dif-1];
            }
        }
        return true;
    }
};