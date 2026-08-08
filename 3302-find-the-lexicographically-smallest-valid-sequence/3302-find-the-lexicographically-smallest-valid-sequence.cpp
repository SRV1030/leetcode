class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int size1 = word1.size();
        int size2 = word2.size();
        vector<int> suffixLen(size1);
        int common = 0;
        for(int ind = size1 - 1, right = size2 - 1; ind >= 0; --ind){
            suffixLen[ind] = common;
            if(right >= 0 && word1[ind] == word2[right]){
                --right;
                ++common;
            }
        }

        vector<int> result;
        bool diff = 0;
        for(int ind1 = 0, ind2 = 0; ind1 < size1 && ind2 < size2; ++ind1){
            if(word1[ind1] == word2[ind2]){
                result.push_back(ind1);
                ++ind2;
            }
            else if(!diff && suffixLen[ind1] >= size2 - ind2 - 1){
                ++ind2;
                diff = 1;
                result.push_back(ind1);
            }
        }
        if(result.size() == size2)
            return  result;
        return {};
    }
};