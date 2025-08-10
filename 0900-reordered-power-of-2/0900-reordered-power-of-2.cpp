class Solution {
public:
    vector<int> digitFrequency(int n){
        vector<int> frequency(10);
        for(; n > 0; n /= 10){
            frequency[n % 10]++;
        }
        return frequency;
    }
    bool equal(const vector<int>& a, const vector<int>& b) {
        for (int index = 0; index < 10; ++index)
            if (a[index] != b[index]) return false;
        return true;
    }
    bool reorderedPowerOf2(int n) {
        vector<int> frequency = digitFrequency(n);
        for(int bit = 0, powerOf2 = 1; bit < 30; ++bit, powerOf2 *= 2){
            if(equal(frequency, digitFrequency(powerOf2)))
                return true;
        }
        return false;
    };
};