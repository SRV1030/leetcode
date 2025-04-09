class Solution {
public:
    vector<int>prefixWeight;
    Solution(vector<int>& w) {
        prefixWeight = w;
        for(int i=1;i<prefixWeight.size();i++)prefixWeight[i]+=prefixWeight[i-1];
    }
    
    int pickIndex() {
        int randomWeight = rand()%prefixWeight.back();
        return upper_bound(prefixWeight.begin(),prefixWeight.end(),randomWeight) - prefixWeight.begin();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */