class Solution {
public:
    vector<int> intersection(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int>s(arr1.begin(),arr1.end());
        vector<int>v;
        for(int i:arr2){
            if(s.erase(i)) v.push_back(i);
        }
        return v;
    }
};