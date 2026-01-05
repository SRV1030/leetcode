class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> mp;
        int length = 0;
        for(int left = 0, right = 0; right < fruits.size(); ++right){
            mp[fruits[right]]++;
            while(mp.size() > 2){
                mp[fruits[left]]--;
                if(!mp[fruits[left]])
                    mp.erase(fruits[left]);
                ++left;
            }
            length = max(length, right - left + 1);
        }
        return length;
    }
};