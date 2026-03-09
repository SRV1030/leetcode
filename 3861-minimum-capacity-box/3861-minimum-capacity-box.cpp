class Solution {
public:
    int minimumIndex(vector<int>& capacity, int itemSize) {
        int minIndex = -1;
        for(int index = 0; index < capacity.size(); ++index){
            if(capacity[index] >= itemSize){
                if(minIndex == -1)
                    minIndex = index;
                else{
                    if(capacity[index] < capacity[minIndex])
                        minIndex = index;
                }
            }
        }
        return minIndex;
    }
};