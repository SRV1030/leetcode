class Solution {
public:
    vector<int> sumZero(int n) {
        int half = n / 2;
        vector<int> result;
        for(int num = 1; num <= half; ++num){
            result.push_back(num);
            result.push_back(-num);
        }
        if(n % 2)
            result.push_back(0);
        return result;
    }
};