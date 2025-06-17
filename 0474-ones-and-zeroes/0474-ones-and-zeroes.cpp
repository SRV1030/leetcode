class Solution {
public: 
    pair<int, int> getZeroOneCount(string str){
        int zeroes = 0, ones = 0;
        for(auto& bit: str){
            if(bit == '0')
                ++zeroes;
            else
                ++ones;
        }
        return {zeroes, ones};
    }

    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<pair<int, int>> zeroOneCounts;
        int size = strs.size(); 
        vector<vector<int>> memory(m + 1, vector<int>(n + 1));

        for(auto& str: strs){
            auto [zeroes, ones] = getZeroOneCount(str); 
            for(int valueOfM = m; valueOfM >= zeroes; --valueOfM){
                for(int valueOfN = n; valueOfN >= ones; --valueOfN){
                    memory[valueOfM][valueOfN] = max(memory[valueOfM][valueOfN], 1 + memory[valueOfM - zeroes][valueOfN - ones]);
                }
            }
        }
        return memory[m][n];
    }
};

// class Solution {
// public: 
//     pair<int, int> getZeroOneCount(string str){
//         int zeroes = 0, ones = 0;
//         for(auto& bit: str){
//             if(bit == '0')
//                 ++zeroes;
//             else
//                 ++ones;
//         }
//         return {zeroes, ones};
//     }

//     int findMaxForm(vector<string>& strs, int m, int n) {
//         vector<pair<int, int>> zeroOneCounts;
//         int size = strs.size(); 
//         vector<vector<vector<int>>> memory(size + 1,vector<vector<int>>(m + 1, vector<int>(n + 1)));
//         for(auto& str: strs)
//             zeroOneCounts.push_back(getZeroOneCount(str));
//         for(int index = size - 1; index >= 0; --index){
//             auto [zeroes, ones] = zeroOneCounts[index]; 
//             for(int valueOfM = 0; valueOfM <= m; ++valueOfM){
//                 for(int valueOfN = 0; valueOfN <= n; ++valueOfN){
//                     memory[index][valueOfM][valueOfN] = memory[index + 1][valueOfM][valueOfN];
//                     if(zeroes <= valueOfM && ones <= valueOfN)
//                         memory[index][valueOfM][valueOfN] = max(memory[index][valueOfM][valueOfN], 1 + memory[index + 1][valueOfM - zeroes][valueOfN - ones]);
//                 }
//             }
//         }
//         return memory[0][m][n];
//     }
// };


// class Solution {
//     vector<pair<int, int>> zeroOneCounts;
//     int size;
//     int memory[601][101][101];
// public: 
//     pair<int, int> getZeroOneCount(string str){
//         int zeroes = 0, ones = 0;
//         for(auto& bit: str){
//             if(bit == '0')
//                 ++zeroes;
//             else
//                 ++ones;
//         }
//         return {zeroes, ones};
//     }
//     int getMaxSubset(int index, int m, int n){
//         if(index >= size || m < 0 || n < 0)
//             return 0;
//         int &maxLength = memory[index][m][n];
//         if(maxLength == -1){
//             maxLength = getMaxSubset(index + 1, m, n);
//             auto [zeroes, ones] = zeroOneCounts[index];
//             if(zeroes <= m && ones <= n)
//                 maxLength = max(maxLength, 1 + getMaxSubset(index + 1, m - zeroes, n - ones));
//         }
//         return maxLength;
//     }
//     int findMaxForm(vector<string>& strs, int m, int n) {
//         size = strs.size(); 
//         memset(memory, -1, sizeof(memory));
//         for(auto& str: strs)
//             zeroOneCounts.push_back(getZeroOneCount(str));
//         return getMaxSubset(0, m, n);
//     }
// };