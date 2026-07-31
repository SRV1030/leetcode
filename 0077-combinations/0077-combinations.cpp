class Solution {
    vector<vector<int>> result;
    vector<int> seq;
public:
    void allPos(int start, int& n, int& k){
        if(seq.size() == k){
            result.push_back(seq);
            return;
        }
        for(int num = start; num <= n; ++num){
            seq.push_back(num);
            allPos(num + 1, n, k);
            seq.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        allPos(1, n, k);
        return result;
    }
};