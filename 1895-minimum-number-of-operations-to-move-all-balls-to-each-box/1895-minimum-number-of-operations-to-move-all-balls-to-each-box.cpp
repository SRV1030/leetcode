class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int>ans(n),v;
        for(int i=0;i<size(boxes);++i)if(boxes[i]=='1')v.push_back(i);
        for(int i=0;i<size(boxes);++i){
            for(auto&j:v)ans[i]+=abs(j-i);
        }
        return ans;
    }
};