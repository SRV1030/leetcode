class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string univ = "123456789";
        vector<int> result;
        int lowSize = to_string(low).size(), highSize = to_string(high).size();
        for(int size = lowSize; size <= highSize; ++size){
            for(int ind = 0; ind + size < 10; ++ind){
                int num = stoi(univ.substr(ind, size));
                if(num >= low && num <= high)
                    result.push_back(num);
            }
        }
        return result;
    }
};