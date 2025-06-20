class Solution {
public:
    int minDistance(string word1, string word2) {
        int sizeOfWord1 = word1.size();
        int sizeOfWord2 = word2.size();
        vector<vector<int>> memory(sizeOfWord1 + 1, vector<int>(sizeOfWord2 + 1));

        for(int index = 0; index <= sizeOfWord1; index++)
            memory[index][sizeOfWord2] = sizeOfWord1 - index;
        for(int index = 0; index <= sizeOfWord2; index++)
            memory[sizeOfWord1][index] = sizeOfWord2 - index;

        for(int index1 = sizeOfWord1 - 1; index1 >= 0; index1--){
            for(int index2 = sizeOfWord2 - 1; index2 >= 0; index2--){
                if(word1[index1] == word2[index2])
                    memory[index1][index2] = memory[index1 + 1][index2 + 1];
                else{
                    memory[index1][index2] = 1 + min({memory[index1 + 1][index2 + 1], memory[index1][index2 + 1], memory[index1 + 1][index2]});
                }
            }
        }
        return memory[0][0];
    }
};

// class Solution {
// public:
//     vector<vector<int>> memory;
//     int sizeOfWord1, sizeOfWord2;
//     int getMinDistance(string word1, string word2, int index1, int index2){
//         if(index1 == sizeOfWord1)
//             return sizeOfWord2 - index2;
//         if(index2 == sizeOfWord2)
//             return sizeOfWord1 - index1;
//         int& minDistance = memory[index1][index2];
//         if(minDistance == -1){
//             if(word1[index1] == word2[index2])
//                 minDistance =  getMinDistance(word1, word2, index1 + 1, index2 + 1);
//             else{
//                 minDistance = 1 + min({getMinDistance(word1, word2, index1 + 1, index2), 
//                                        getMinDistance(word1, word2, index1, index2 + 1),
//                                        getMinDistance(word1, word2, index1 + 1, index2 + 1)});
//             }
//         }
//         return minDistance;
//     }
//     int minDistance(string word1, string word2) {
//         sizeOfWord1 = word1.size();
//         sizeOfWord2 = word2.size();
//         memory = vector<vector<int>> (sizeOfWord1 + 1, vector<int>(sizeOfWord2, -1));
//         return getMinDistance(word1, word2, 0, 0);
//     }
// };