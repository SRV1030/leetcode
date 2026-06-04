class Solution {
    vector<int> waviness, prefix;
public:
    void fillWave(int num){
        prefix.resize(num + 1);
        if(num <= 100)
            return;
        waviness.resize(num + 1);
        for(int ind = 101; ind <= num; ++ind){
            int right = ind % 10;
            int mid = (ind / 10) % 10;
            int left = (ind / 100) % 10;
            waviness[ind] = waviness[ind / 10] + ((mid > left && mid > right) || (mid < left && mid < right));
            prefix[ind] = waviness[ind] + prefix[ind - 1];
        }
        return;
    }
    int totalWaviness(int num1, int num2) {
        fillWave(num2);
        return prefix[num2] - prefix[num1 - 1];
    }
};