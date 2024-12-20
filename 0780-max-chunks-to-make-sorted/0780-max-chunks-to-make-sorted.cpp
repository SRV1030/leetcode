class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int ch=0,pfx=0,stpfx=0;
        for(int i=0;i<arr.size();++i){
            pfx+=arr[i];
            stpfx+=i;
            if(pfx==stpfx)++ch;
        }
        return ch;
    }
};