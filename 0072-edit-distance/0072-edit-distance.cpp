class Solution {
    vector<vector<int>> memory;
    int size1, size2;
public:
    int minSubs(string word1, string word2, int index1, int index2){
        if(index1 == size1)
            return size2 - index2;
        if(index2 == size2)
            return size1 - index1;
        int& subs = memory[index1][index2];
        if(subs == -1){
            if(word1[index1] == word2[index2])
                subs = minSubs(word1, word2, index1 + 1, index2 + 1);
            else{
                subs = 1 + min({
                    minSubs(word1, word2, index1 + 1, index2 + 1),
                    minSubs(word1, word2, index1, index2 + 1),
                    minSubs(word1, word2, index1 + 1, index2)
                });
            }
        }
        return subs;  
    }   
    int minDistance(string word1, string word2) {
        size1 = word1.size();
        size2 = word2.size();
        memory = vector<vector<int>> (size1, vector<int> (size2, -1));
        return minSubs(word1, word2, 0, 0);
    }
};