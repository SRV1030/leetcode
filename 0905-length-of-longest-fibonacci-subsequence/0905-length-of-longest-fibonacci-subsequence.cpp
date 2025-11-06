class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        unordered_set<int> avl;
        int size = arr.size(), result = 0;
        for(int ind = size - 1; ind >= 0; --ind){
            for(int pInd = ind - 1; pInd >= 0; --pInd){
                if(avl.count(arr[ind] + arr[pInd])){
                    int count = 3;
                    int prev = arr[ind], curr = arr[ind] + arr[pInd];
                    while(avl.count(prev + curr)){
                        ++count;
                        int temp = prev + curr;
                        prev = curr;
                        curr = temp;
                    }
                    result = max(result, count);
                }
            }
            avl.insert(arr[ind]);
        }
        return result;
    }
};