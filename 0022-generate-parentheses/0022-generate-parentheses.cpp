class Solution {
public:
    vector<string> result;
    void fill(int open, int closed, string eqn){
        if(!closed){
            result.push_back(eqn);
            return;
        }
        if(open)
            fill(open - 1, closed, eqn + "(");
        if(open < closed)
            fill(open, closed - 1, eqn + ")");
    }
    vector<string> generateParenthesis(int n) {
        fill(n, n, "");
        return result;
    }
};