class Solution {
public:
    int nextGreaterElement(int num) {
        if(num == INT_MAX)
            return -1;
        string numStr = to_string(num);
        for(int index = numStr.size() - 2; index >= 0; --index){
            if(numStr[index] < numStr[index + 1]){
                int j = numStr.size() - 1;
                while(index < j && numStr[index] >= numStr[j])
                    --j;
                swap(numStr[index], numStr[j]);
                reverse(numStr.begin() + index + 1, numStr.end());
                long long val = stoll(numStr);
                if (val > INT_MAX)
                    return -1;
                return val;
            }
        }

        return -1;
    }
};