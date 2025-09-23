class Solution {
public:
    int calculate(string s) {
        stack<int> numStack;
        int sign = 1, num = 0, result = 0;
        for(auto& character : s){
            if(isdigit(character))
                num = num * 10 + (character - '0');
            else if(character == '+' || character == '-'){
                result += num * sign;
                num = 0;
                sign = character == '+' ? 1 : -1;
            }
            else if(character == '('){
                numStack.push(result);
                numStack.push(sign);
                result = num = 0;
                sign = 1;
            }
            else if(character == ')'){
                result += num * sign;
                result *= numStack.top();
                numStack.pop();
                result += numStack.top();
                numStack.pop();
                num = 0;
                sign = 1;
            }
        }
        if(num)
            result += (num * sign);
        return result;
    }
};