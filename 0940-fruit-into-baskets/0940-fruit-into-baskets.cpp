class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> uniqueFruits;
        int maxLength = 0;
        for(int left = 0, right = 0; right < fruits.size(); ++right){
            uniqueFruits[fruits[right]]++;
            while(uniqueFruits.size() > 2){
                uniqueFruits[fruits[left]]--;
                if(!uniqueFruits[fruits[left]]){
                    uniqueFruits.erase(fruits[left]);
                }
                ++left;
            }
            maxLength = max(maxLength, right - left + 1);
        }
        return maxLength;
    }
};