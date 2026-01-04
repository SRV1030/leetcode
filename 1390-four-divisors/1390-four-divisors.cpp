class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int sum = 0;
        for(auto& num : nums){
            int div = 0;
            for(int intg = 2; intg * intg <= num; ++intg){
                if(num % intg == 0){
                    if(div == 0)
                        div = intg;
                    else{
                        div = 0;
                        break;
                    }
                }
            }
            if(div && (num / div != div))
                sum += (1 + div + num + num / div);
        }
        return sum;
    }
};