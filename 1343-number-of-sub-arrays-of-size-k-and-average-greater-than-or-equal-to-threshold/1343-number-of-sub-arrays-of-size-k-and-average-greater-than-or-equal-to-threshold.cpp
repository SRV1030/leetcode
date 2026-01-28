class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        vector<int> pfs(arr.size() + 1);
        for(int index = 0; index < arr.size(); ++index)
            pfs[index + 1] = pfs[index] + arr[index];
        int count = 0;
        for(int index = 0; index + k <= arr.size(); ++index){
            if(pfs[index + k] - pfs[index] >= threshold * k)
                ++count;
        }
        return count;
    }
};