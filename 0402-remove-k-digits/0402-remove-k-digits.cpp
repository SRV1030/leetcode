class Solution {
public:
    string removeKdigits(string num, int k) {
        if(k >= num.size())
            return "0";
        stack<char> digits;
        for(auto& charDigit : num){
            while(k && !digits.empty() && charDigit < digits.top()){
                digits.pop();
                k--;
            }
            if(digits.empty() && charDigit == '0')
                continue;
            digits.push(charDigit);
        }
        while(!digits.empty() && k--)
            digits.pop();
        string smallestNum;
        while(!digits.empty()){
            smallestNum.insert(smallestNum.begin(), digits.top());
            digits.pop();
        }
        return smallestNum.empty() ? "0" : smallestNum;
    }
};