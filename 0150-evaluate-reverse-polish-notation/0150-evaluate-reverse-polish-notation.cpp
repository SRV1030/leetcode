class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> simulator;

        for (auto& token : tokens) {
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                int right = simulator.top(); simulator.pop();
                int left = simulator.top(); simulator.pop();

                if (token == "+") simulator.push(left + right);
                else if (token == "-") simulator.push(left - right);
                else if (token == "*") simulator.push(left * right);
                else simulator.push(left / right); 
            } 
            else {
                simulator.push(stoi(token));
            }
        }

        return simulator.top();
    }
};
