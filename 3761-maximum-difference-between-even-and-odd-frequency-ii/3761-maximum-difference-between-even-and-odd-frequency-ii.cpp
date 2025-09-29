class Solution {
    int getStatus(int countA, int countB){
        return (countA & 1) << 1 | (countB & 1);
    }
public:
    int maxDifference(string s, int k) {
        int size = s.size();
        int maxDiff = INT_MIN;
        for(char a = '0'; a <= '4'; ++a){
            for(char b = '0'; b <= '4'; ++b){
                if(a == b)
                    continue;
                
                int best[4] = {INT_MAX, INT_MAX, INT_MAX, INT_MAX};
                int countA = 0, countB = 0, prevCA = 0, prevCB = 0;
                int left = -1;
                for(int right = 0; right < size; ++right){
                    countA += (s[right] == a);
                    countB += (s[right] == b);

                    while((right - left) >= k && (countB - prevCB) >= 2){
                        int leftStatus = getStatus(prevCA, prevCB);
                        best[leftStatus] = min(best[leftStatus], prevCA - prevCB);
                        ++left;
                        prevCA += (s[left] == a);
                        prevCB += (s[left] == b);
                    }

                    int rightStatus = getStatus(countA, countB);

                    if(best[rightStatus ^ 2] != INT_MAX){
                         maxDiff = max(maxDiff, countA - countB - best[rightStatus ^ 2]);
                    }

                }
            }
        }
        return maxDiff;
    }
};