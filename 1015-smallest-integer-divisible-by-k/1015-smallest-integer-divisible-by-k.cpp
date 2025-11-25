class Solution {
public:
    int smallestRepunitDivByK(int k) {
        int num = 0;
        for(int index = 1; index <= k; ++index){
            num = (num * 10 + 1) % k;
            if(num == 0)
                return index;
        }
        return -1;
    }
};