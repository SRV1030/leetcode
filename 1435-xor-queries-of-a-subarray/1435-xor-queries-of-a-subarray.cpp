class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        for(int i=1;i<size(arr);++i)arr[i]^=arr[i-1];
        vector<int>result;
        for(auto&i:queries){
            result.push_back(i[0]>0?arr[i[1]]^arr[i[0]-1]:arr[i[1]]);
        }
        return result;
    }
};