class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        string push = "Push", pop = "Pop";
        vector<string> result;
        int prev = 0;
        for(auto& num : target){
            int diff = num - prev;
            if(diff == 1)
                result.push_back(push);
            else{
                --diff;
                while(diff--){
                    result.push_back(push);
                    result.push_back(pop);
                }
                result.push_back(push);
            }
            prev = num;
        }
        return result;
    }
};