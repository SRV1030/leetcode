class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        vector<int>sortedArr(begin(arr),end(arr));
        int size = arr.size();
        sort(sortedArr.begin(),sortedArr.end());
        long long diff = 0;
        int chunks=0;
        for(int i=0;i<size;i++){
            diff += arr[i]-sortedArr[i];
            if(!diff) chunks++;
        }
        return chunks;
    }
};