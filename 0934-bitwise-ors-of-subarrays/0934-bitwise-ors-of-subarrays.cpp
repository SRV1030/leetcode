class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> resultOrs, previousOrs;
        for(auto& num: arr){
            unordered_set<int> runningOrs;
            runningOrs.insert(num);
            for(auto& ors: previousOrs)
                runningOrs.insert(num | ors);
            resultOrs.insert(runningOrs.begin(), runningOrs.end());
            previousOrs = runningOrs;
        }
        return resultOrs.size();
    }
};