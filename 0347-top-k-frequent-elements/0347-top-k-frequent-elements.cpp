class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int sizeOfNums = nums.size();
        unordered_map<int, int> numToFrequencyMap;

        for(auto& num: nums)
            numToFrequencyMap[num]++;

        vector<vector<int>> frequencyList(sizeOfNums + 1);

        for(auto& [num, frequency]: numToFrequencyMap)
            frequencyList[frequency].push_back(num);

        vector<int> topKFrequentElements;

        for(int index = sizeOfNums; index >= 0 && k; index--){
            if(frequencyList[index].size()){
                for(auto& num: frequencyList[index]){
                    topKFrequentElements.push_back(num);
                    if (--k == 0)
                        break;
                }
            }
        }
        return topKFrequentElements;
    }
};