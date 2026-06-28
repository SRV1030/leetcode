class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int size = arr.size();
        sort(arr.begin(), arr.end());
        arr[0] = 1;
        for(int ind = 1; ind < size; ++ind){
            if(arr[ind] - arr[ind - 1] >= 1)
                arr[ind] = 1 + arr[ind - 1];
            else
                arr[ind] = arr[ind - 1];
        }
        return arr[size - 1];
    }
};