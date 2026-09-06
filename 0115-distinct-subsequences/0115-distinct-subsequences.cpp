class Solution {
public:
    int numDistinct(string s, string t) {
        long long sizeOfS = s.size(), sizeOfT = t.size();
        vector<vector<unsigned long long>> memory(sizeOfS + 1, vector<unsigned long long>(sizeOfT + 1));
        for(int index = 0; index <= sizeOfS; index++)
            memory[index][sizeOfT] = 1;
        for(int indexOfS = sizeOfS - 1; indexOfS >= 0; --indexOfS)
            for(int indexOfT = sizeOfT - 1; indexOfT >= 0; --indexOfT){
                memory[indexOfS][indexOfT] = memory[indexOfS + 1][indexOfT];
                if(s[indexOfS] == t[indexOfT])
                     memory[indexOfS][indexOfT] +=  memory[indexOfS + 1][indexOfT + 1];
            }
        return memory[0][0];
    }
};

// class Solution {
//     int memory[1001][1001];
// public:
//     int countSubsequences(string s, string t, int indexOfS = 0, int indexOfT = 0){
//         if(indexOfT == t.size())
//             return 1;
//         if(indexOfS == s.size())    
//             return 0;

//         int& subsequenceCount = memory[indexOfS][indexOfT];
//         if(subsequenceCount == -1){
//             subsequenceCount = countSubsequences(s, t, indexOfS + 1, indexOfT);
//             if(s[indexOfS] == t[indexOfT])
//                 subsequenceCount += countSubsequences(s, t, indexOfS + 1, indexOfT + 1);
//         }
//         return subsequenceCount;
//     }
//     int numDistinct(string s, string t) {
//         memset(memory, -1, sizeof(memory));
//         return countSubsequences(s, t);
//     }
// };